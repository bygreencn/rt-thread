/*
 * File      : app.c
 * This file is part of RT-Thread RTOS
 * COPYRIGHT (C) 2006, RT-Thread Development Team
 *
 * The license and distribution terms for this file may be
 * found in the file LICENSE in this distribution or at
 * http://www.rt-thread.org/license/LICENSE
 *
 * Change Logs:
 * Date           Author       Notes
 * 2010-01-25     Bernard      first version
 */

/**
 * @addtogroup LPC1100
 */
/*@{*/
#include <rtthread.h>
#include <lpc11xx.h>
#include <gpio.h>

/* The bit on port 0 to which the LED is wired. */
#define LED_BIT		( 1UL << 7UL )
static void SetupLEDHardware ( void )
{
    GPIOInit();
    GPIOSetDir ( PORT2, PIN_6, OUT );
    GPIOSetDir ( PORT2, PIN_7, OUT );
    GPIOSetValue ( PORT2, PIN_6, 0 );
    GPIOSetValue ( PORT2, PIN_7, 0 );
}
void led_thread_entry ( void* parameter )
{
    int pin = ( int ) parameter;
    int delay = 1;
    if ( pin & 0x01 )
        delay = 1;
    else
        delay = 2;
    GPIOSetDir ( PORT2, pin, OUT );
		
    while ( 1 )
    {
        rt_thread_delay ( RT_TICK_PER_SECOND / delay );
        GPIOSetValue ( PORT2, pin, 1 );
        rt_thread_delay ( RT_TICK_PER_SECOND / delay );
        GPIOSetValue ( PORT2, pin, 0 );
    }
}

void led_thread_init ( void )
{
    rt_thread_t tid;
    /* create a thread */
    tid = rt_thread_create ( "led1", led_thread_entry, ( void* ) 6, 1024, 20, 10 );
    if ( tid != RT_NULL )
    {
        rt_thread_startup ( tid );
    }
    tid = rt_thread_create ( "led2", led_thread_entry, ( void* ) 7, 1024, 21, 10 );
    if ( tid != RT_NULL )
    {
        rt_thread_startup ( tid );
    }
}


int rt_application_init()
{
    SetupLEDHardware();

		led_thread_init();

    return 0;
}

/*@}*/
