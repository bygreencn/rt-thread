#include "LPC11xx.h"			
#include "wdt.h"
#include "clkconfig.h"
/****************************************
              WDT_IRQHandler
�������� : ���Ź�������жϷ������
�������� : ��
����ֵ   : ��
****************************************/
void WDT_IRQHandler(void)
{
    LPC_WDT->MOD &= ~WDTOF;		 //�嶨ʱ�������־
    LPC_WDT->MOD &= ~WDINT;		 //�忴�Ź��жϱ�־λ
}

/****************************************
              WDTInit
�������� : ���Ź���ʼ��
           ���Ź���ʱ��Ĭ��Ϊ1.6MHZ/6=270KHZ
		   ���ڿ��Ź�������ʱ����4��ƵTWDCLK
		   �ʶ�ʱ����Ϊ270KHZ/4=67.5KHZ
�������� : ��
����ֵ   : ��
****************************************/
void WDTInit( void )
{
    LPC_SYSCON->SYSAHBCLKCTRL |= (1<<15);   //ʹ�ܿ��Ź�ʱ��
    NVIC_EnableIRQ(WDT_IRQn);			    //�����Ź��ж�
	WDT_CLK_Setup(WDTCLK_SRC_WDT_OSC);      //���ÿ��Ź�ʱ��Դ
    LPC_WDT->TC   = WDT_FEED_VALUE;	        //һ��WDENʹ�� �����Ź�����feed��ʼ����
    LPC_WDT->MOD  = WDEN | WDRESET;		    //��λģʽ(�����Ź����������,ֻ��λ�������ж�)
    LPC_WDT->FEED = 0xAA;		            //ι����������������˳���ܴ�
    LPC_WDT->FEED = 0x55;    
}

/****************************************
              WDTFeed
�������� : ι��(˳���ܵߵ�)
�������� : ��
����ֵ   : ��
****************************************/
void WDTFeed( void )
{
    LPC_WDT->FEED = 0xAA;		
    LPC_WDT->FEED = 0x55;
}


