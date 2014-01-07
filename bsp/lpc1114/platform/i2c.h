/******************** (C) COPYRIGHT 2010 Embest Info&Tech Co.,LTD. ************
* �ļ���: i2c.h
* ����  : Wuhan R&D Center, Embest
* ����  : 01/18/2010
* ����  : NXP LPC11xx ϵ�д����� I2C ģ��ͷ�ļ�.
*******************************************************************************
*******************************************************************************
* ��ʷ:
* 01/18/2010		 : V1.0		   ��ʼ�汾
*******************************************************************************/

#ifndef __I2C_H 
#define __I2C_H

/* ������I2C SEEPROMʱ���轫FAST_MODE_PLUS��0�������а�����ʱ���轫��λ��1 */
#define FAST_MODE_PLUS	0

#define IIC_BUFSIZE		64
#define MAX_TIMEOUT		0x00FFFFFF

#define I2CMASTER		0x01
#define I2CSLAVE		0x02

#define CAT24C02_ADDR	0xA0
//#define READ_WRITE		0x01

#define RD_BIT			0x01

#define I2C_IDLE			 0
#define I2C_STARTED			 1
#define I2C_RESTARTED		 2
#define I2C_REPEATED_START	 3
#define DATA_ACK			 4
#define DATA_NACK			 5
#define I2C_BUSY             6
#define I2C_NO_DATA          7
#define I2C_NACK_ON_ADDRESS  8
#define I2C_NACK_ON_DATA     9
#define I2C_ARBITRATION_LOST 10
#define I2C_TIME_OUT         11
#define I2C_OK               12

#define I2CONSET_I2EN		0x00000040  /* I2C�������üĴ��� */
#define I2CONSET_AA			0x00000004
#define I2CONSET_SI			0x00000008
#define I2CONSET_STO		0x00000010
#define I2CONSET_STA		0x00000020

#define I2CONCLR_AAC		0x00000004  /* I2C��������Ĵ��� */
#define I2CONCLR_SIC		0x00000008
#define I2CONCLR_STAC		0x00000020
#define I2CONCLR_I2ENC		0x00000040

#define I2DAT_I2C			0x00000000  /* I2C���ݼĴ��� */
#define I2ADR_I2C			0x00000000  /* I2C�ӵ�ַ�Ĵ��� */
#define I2SCLH_SCLH			0x00000180  /* I2C SCLռ�ձȸߵ�ƽ�Ĵ��� */
#define I2SCLL_SCLL			0x00000180  /* I2C SCLռ�ձȵ͵�ƽ�Ĵ��� */
#define I2SCLH_HS_SCLH		0x00000030  /* ��������ģʽI2C SCLռ�ձȸߵ�ƽ�Ĵ��� */
#define I2SCLL_HS_SCLL		0x00000030  /* ��������ģʽI2C SCLռ�ձȵ͵�ƽ�Ĵ��� */

extern volatile uint32_t I2CCount;
extern volatile uint8_t  I2CMasterBuffer[IIC_BUFSIZE];
extern volatile uint8_t  I2CSlaveBuffer [IIC_BUFSIZE];
extern volatile uint32_t I2CMasterState;
extern volatile uint32_t I2CReadLength, I2CWriteLength;

extern void I2C_IRQHandler( void );
extern uint32_t I2CInit( uint32_t I2cMode );
extern uint32_t I2CStart( void );
extern uint32_t I2CStop( void );
extern uint32_t I2CEngine( void );
extern void I2C_WriteByte( uint8_t Dev_WR_Addr,uint8_t DataAddr,uint8_t Data );
extern void I2C_Write(volatile uint8_t *Pdata,uint8_t Len,uint8_t DataAddr,uint8_t Dev_WR_Addr);
extern uint8_t I2C_ReadByte( uint8_t Dev_WR_Addr,uint8_t DataAddr ); 
extern void I2C_Read(volatile uint8_t *Pdata,uint8_t Len,uint8_t DataAddr,uint8_t Dev_WR_Addr ); 
//extern void I2C_Write( uint8_t Dev_WR_Addr,uint8_t DataAddr,uint8_t *Pdata,volatile uint8_t *WriteBuff,volatile uint32_t W_Len,volatile uint32_t R_Len ,uint32_t Len); 
																						 
#endif /* end __I2C_H */
/**
  * @}
  */ 

/**
  * @}
  */ 

/************* (C) COPYRIGHT 2010 Wuhan R&D Center, Embest *****�ļ�����*******/
