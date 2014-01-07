/****************************************************************************
 *   $Id:: gpio.h 4067 2010-07-30 02:23:08Z usb00423                        $
 *   Project: NXP LPC11xx software example
 *
 *   Description:
 *     This file contains definition and prototype for GPIO.
 *
 ****************************************************************************
 * Software that is described herein is for illustrative purposes only
 * which provides customers with programming information regarding the
 * products. This software is supplied "AS IS" without any warranties.
 * NXP Semiconductors assumes no responsibility or liability for the
 * use of the software, conveys no license or title under any patent,
 * copyright, or mask work right to the product. NXP Semiconductors
 * reserves the right to make changes in the software without
 * notification. NXP Semiconductors also make no representation or
 * warranty that such application will be suitable for the specified
 * use without further testing or modification.
****************************************************************************/
#ifndef __GPIO_H 
#define __GPIO_H

#define PORT0		0
#define PORT1		1
#define PORT2		2
#define PORT3		3

#define OUT			1
#define IN			0
#define PIN_0		0
#define PIN_1		1
#define PIN_2		2
#define PIN_3		3
#define PIN_4		4
#define PIN_5		5
#define PIN_6		6
#define PIN_7		7
#define PIN_8		8
#define PIN_9		9
#define PIN_10		10
#define PIN_11		11	  

#define SET         1
#define RESET		0
//#define CLKOUT_DIV_Val       1			//CLKOUT时钟分频系数

#define  __JTAG_DISABLED	           //禁止JTAG功能
static LPC_GPIO_TypeDef (* const LPC_GPIO[4]) = { LPC_GPIO0, LPC_GPIO1, LPC_GPIO2, LPC_GPIO3 };
void PIOINT0_IRQHandler(void);
void PIOINT1_IRQHandler(void);
void PIOINT2_IRQHandler(void);
void PIOINT3_IRQHandler(void);
void GPIOInit( void );
void GPIOSetInterrupt( uint32_t portNum, uint32_t bitPosi, uint32_t sense,
uint32_t single, uint32_t event );
void GPIOIntEnable( uint32_t portNum, uint32_t bitPosi );
void GPIOIntDisable( uint32_t portNum, uint32_t bitPosi );
uint32_t GPIOIntStatus( uint32_t portNum, uint32_t bitPosi );
void GPIOIntClear( uint32_t portNum, uint32_t bitPosi );
void GPIOSetValue( uint32_t portNum, uint32_t bitPosi, uint32_t bitVal );
void GPIOSetDir( uint32_t portNum, uint32_t bitPosi, uint32_t dir );
void GPIO_TOGGLE( uint32_t portNum, uint32_t bitPosi );
uint8_t READ_GPIOBIT(uint32_t portNum, uint32_t bitPosi );
uint32_t READ_GPIO(uint32_t portNum, uint32_t Posi );
void SET_GPIO( uint32_t portNum, uint32_t Posi, uint32_t Val );
																
#endif /* end __GPIO_H */
/*****************************************************************************
**                            End Of File
******************************************************************************/
