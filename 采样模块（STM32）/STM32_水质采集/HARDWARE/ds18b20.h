#ifndef _ds18b20_H
#define _ds18b20_H
#include "stm32f4xx.h"                  // Device header
#include "Delay.h"
#include "Sys.h"

extern u16 DS18B20_temp;

/*  DS18B20ʱ�Ӷ˿ڡ����Ŷ��� */
#define DS18B20_PORT 			GPIOE 
#define DS18B20_PIN 			(GPIO_Pin_0)
#define DS18B20_PORT_RCC		RCC_AHB1Periph_GPIOE


////IO��������											   
#define	DS18B20_DQ_OUT PEout(0) //���ݶ˿�	PG11
#define	DS18B20_DQ_IN  PEin(0)  //���ݶ˿�	PG11 
   	
u8 DS18B20_Init(void);			//��ʼ��DS18B20
float DS18B20_GetTemperture(void);	//��ȡ�¶�
void DS18B20_Start(void);		//��ʼ�¶�ת��
void DS18B20_Write_Byte(u8 dat);//д��һ���ֽ�
u8 DS18B20_Read_Byte(void);		//����һ���ֽ�
u8 DS18B20_Read_Bit(void);		//����һ��λ
u8 DS18B20_Check(void);			//����Ƿ����DS18B20
void DS18B20_Reset(void);			//��λDS18B20   




#endif
