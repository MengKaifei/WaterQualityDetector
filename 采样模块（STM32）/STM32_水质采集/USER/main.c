#include "stm32f4xx.h"                 
#include "LED.h"
#include "Delay.h"
#include "Serial.h"     
#include "LCD.h"
#include "L610.h"
#include "DS18B20.h"
#include "ADC.h"
#include "ccd.h"

double TDS_K_value=0.1;//TDS����ϵ��

int main(void)
{ 
	char Str_Temp[20];
	uint16_t ADC_Temp;
	uint16_t i_p;
	uint16_t USART2_SendTemp1;
	uint16_t USART2_SendTemp2;
	uint16_t p_i;
	double Temperature;
	double TDS;
	double PH;
	
	uint16_t Loop_Count=0;
	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	delay_init(168);
	LED_Init();
		
	Serial_Init();
	LCD_Init();
	USART2_Init();
	L610_Init();
	
	Adc3_Init();
	CCD_Init();
	while(DS18B20_Init())//�ȴ��¶ȴ�������ʼ���ɹ�
	{
		printf("DS18B20ʧ��!\r\n");
		delay_ms(500);
	}
	printf("DS18B20�ɹ�\r\n");
	while(1)  
	{
		if(USART2_CheckPack()==1)
		{
			LED2=!LED2;
			switch(USART2_BUF[1])
			{
				case 0x01://����о1B����PH����
					ADC_Temp=Get_Adc(10);//PHADCֵ��ȡ//PC0 ͨ��10
					PH=((double)ADC_Temp/4095.0)*5.0;
					PH=(-5.8887*PH+21.677)*0.6;
				
					USART2_SendTemp1=((uint32_t)PH);
					USART2_SendTemp2=(uint32_t)(PH*100);
					USART2_SendPack(0x01,USART2_SendTemp1,USART2_SendTemp2);
					break;
				case 0x02://����о1B�����¶�����
					Temperature=DS18B20_GetTemperture();
					USART2_SendTemp1=((uint32_t)Temperature);
					USART2_SendTemp2=(uint32_t)(Temperature*100);
					USART2_SendPack(0x02,USART2_SendTemp1,USART2_SendTemp2);
					break;
				case 0x03://����о1B����TDS����
					ADC_Temp=Get_Adc(11);//TDSADCֵ��ȡ//PC1 ͨ��11
					TDS=(ADC_Temp/4095.0)*3.3*(1.0+0.02*(Temperature-25.0));
					TDS = (66.71*TDS*TDS*TDS - 127.93*TDS*TDS + 428.7*TDS) * TDS_K_value;//��ȡTDS����ֵ
					if(TDS<0)TDS=0;
					else if(TDS>1400.0)TDS=1400.0;
				
					USART2_SendTemp1=((uint32_t)TDS);
					USART2_SendTemp2=(uint32_t)(TDS*100);
					USART2_SendPack(0x03,USART2_SendTemp1,USART2_SendTemp2);
					break;
				case 0x04://����о1B����CCD����
					for(p_i=0;p_i<3994/2;p_i++)
					{
						USART2_SendPack(0x03,ADC_ConvertedValue[p_i],ADC_ConvertedValue[p_i+1]);
					}
					
					break;
				default:break;
			}
		}
		
	
		Loop_Count++;
		if(Loop_Count>=1000)
		{
			Loop_Count=0;

			Temperature=DS18B20_GetTemperture();//�¶Ȼ�ȡ
		
			ADC_Temp=Get_Adc(11);//TDSADCֵ��ȡPC1
			printf("ADC_Temp1=%d\r\n",ADC_Temp);
			TDS=(ADC_Temp/4095.0)*3.3*(1.0+0.02*(Temperature-25.0));
			TDS = (66.71*TDS*TDS*TDS - 127.93*TDS*TDS + 428.7*TDS) * TDS_K_value;//��ȡTDS����ֵ
			if(TDS<0)TDS=0;
			else if(TDS>1400.0)TDS=1400.0;

			
			ADC_Temp=Get_Adc(10);//PHADCֵ��ȡPC0
			printf("ADC_Temp2=%d\r\n",ADC_Temp);//PH��ȡ
			PH=((double)ADC_Temp/4095.0)*5.0;
			PH=(-5.8887*PH+21.677)*0.6;
			
			sprintf(Str_Temp,"%.2f",Temperature);
			L610_SendData("Temperature",Str_Temp);//������������¶�����
			
			sprintf(Str_Temp,"%.2f",TDS);
			L610_SendData("TDS",Str_Temp);//�����������TDS����
			
			sprintf(Str_Temp,"%.2f",PH);
			L610_SendData("PH",Str_Temp);//�����������PH����
			
			CCD_Read();//ccd��ȡ
			delay_ms(20);//�ȶ�ȡ���
			for(p_i=0;p_i<3994;p_i+=20)
			{
				printf("%d,",ADC_ConvertedValue[p_i]);//�����������CCD����
			}
			printf("0,0]}}\"\r\n");//����
			LED1=!LED1;//״ָ̬ʾ
		}
		delay_ms(1);
	}
}




