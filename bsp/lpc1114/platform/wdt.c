#include "LPC11xx.h"			
#include "wdt.h"
#include "clkconfig.h"
/****************************************
              WDT_IRQHandler
函数功能 : 看门狗初溢出中断服务程序
参数描述 : 无
返回值   : 无
****************************************/
void WDT_IRQHandler(void)
{
    LPC_WDT->MOD &= ~WDTOF;		 //清定时器溢出标志
    LPC_WDT->MOD &= ~WDINT;		 //清看门狗中断标志位
}

/****************************************
              WDTInit
函数功能 : 看门狗初始化
           看门狗的时钟默认为1.6MHZ/6=270KHZ
		   由于看门狗计数器时钟是4分频TWDCLK
		   故定时周期为270KHZ/4=67.5KHZ
参数描述 : 无
返回值   : 无
****************************************/
void WDTInit( void )
{
    LPC_SYSCON->SYSAHBCLKCTRL |= (1<<15);   //使能看门狗时钟
    NVIC_EnableIRQ(WDT_IRQn);			    //允许看门狗中断
	WDT_CLK_Setup(WDTCLK_SRC_WDT_OSC);      //配置看门狗时钟源
    LPC_WDT->TC   = WDT_FEED_VALUE;	        //一旦WDEN使能 ，看门狗将在feed后开始工作
    LPC_WDT->MOD  = WDEN | WDRESET;		    //复位模式(即看门狗计数溢出后,只复位不产生中断)
    LPC_WDT->FEED = 0xAA;		            //喂狗启动狗计数器（顺序不能错）
    LPC_WDT->FEED = 0x55;    
}

/****************************************
              WDTFeed
函数功能 : 喂狗(顺序不能颠倒)
参数描述 : 无
返回值   : 无
****************************************/
void WDTFeed( void )
{
    LPC_WDT->FEED = 0xAA;		
    LPC_WDT->FEED = 0x55;
}


