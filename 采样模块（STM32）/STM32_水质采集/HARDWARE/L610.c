#include "Serial.h"                  // Device header
#include "lcd.h"
#include "delay.h"
#include <string.h>
#include "L610.h"


unsigned char _4G_BUF[300];
uint8_t Rx_p=0;
	
void Clear_Buffer(void)
{
	uint8_t i;
 
	for(i=0;i<Rx_p;i++)
	_4G_BUF[i]=0;
	Rx_p=0;
}	
	
//LCD��ʾ������Ϣ����	
void _LCD_Show4GBUF(uint8_t*_4G_BUF,uint8_t Len)	
{
	uint8_t p=0;
	uint8_t p_x=0;
	static uint16_t p_y=0;

	while(p<Len)
	{
		if(_4G_BUF[p]>=' '&&_4G_BUF[p]<='~')//�ж��ڲ�����ʾ�����
		{
			LCD_ShowChar(p_x*12, p_y,_4G_BUF[p], 24, 0);
			
		}
		else if(_4G_BUF[p-1]=='\r'&&_4G_BUF[p]=='\n')//���з�
		{
			p_y+=24;
			p_x=0;
		}
		p++;
		p_x++;
		if(p_x>40)
		{
			p_x=0;
			p_y+=24;
		}
		
		if(p_y>800)
		{
			LCD_Clear(BACK_COLOR);
			p_y=0;
		}
	}
}



void L610_Init(void)
{
	char *strx;
	
	delay_ms(5000);
	
	Rx_p=0;
	printf("AT\r\n");//���ģ��
	delay_ms(1000);
	strx=strstr((const char*)_4G_BUF,(const char*)"OK");
	while(strx==NULL)//ģ����ʧ��
	{
		_LCD_Show4GBUF((uint8_t *)"L610_ERR\r\n",10);
		delay_ms(1000);
		Clear_Buffer();
		printf("AT\r\n");//���ģ��
		delay_ms(1000);
		strx=strstr((const char*)_4G_BUF,(const char*)"OK");
	}
	_LCD_Show4GBUF(_4G_BUF,Rx_p);//ģ�����ӳɹ�LCD��ʾ��������	

	Rx_p=0;
	printf("AT+CGMR?\r\n");//��ѯģ��汾
	delay_ms(1000);
	_LCD_Show4GBUF(_4G_BUF,Rx_p);	
	
	Rx_p=0;
	printf("AT+CPIN?\r\n");//��ѯģ��汾
	delay_ms(1000);
	_LCD_Show4GBUF(_4G_BUF,Rx_p);	
	
	Rx_p=0;
	printf("AT+CSQ\r\n");//ȷ�ϵ�ǰ�ź�ǿ�ȡ�
	delay_ms(1000);
	_LCD_Show4GBUF(_4G_BUF,Rx_p);	
	
	Rx_p=0;
	printf("AT+CGREG?\r\n");//��ѯ PS �����ݷ����Ƿ���ã�1 ���� 5 ����
	delay_ms(1000);
	_LCD_Show4GBUF(_4G_BUF,Rx_p);	
	
	
	Rx_p=0;
	printf("AT+COPS?\r\n");//��ѯ��ǰ������Ӫ�̺�������ʽ����ѡ��
	delay_ms(1000);
	_LCD_Show4GBUF(_4G_BUF,Rx_p);	
	
	Rx_p=0;
	printf("AT+MIPCALL?\r\n");//����ȴ� IP ���������������
	delay_ms(1000);
	_LCD_Show4GBUF(_4G_BUF,Rx_p);
	
	Rx_p=0;
	printf("AT+MIPCALL=1\r\n");//��ѯ��ǰ������Ӫ�̺�������ʽ����ѡ��
	delay_ms(1000);
	_LCD_Show4GBUF(_4G_BUF,Rx_p);
	
	Rx_p=0;
	printf("AT+MIPCALL?\r\n");//����ȴ� IP ���������������
	delay_ms(1000);
	_LCD_Show4GBUF(_4G_BUF,Rx_p);
	
	Rx_p=0;
	printf("AT+TCDEVINFOSET=1,\"5DOXOMOIXC\",\"device1\",\"8ypX2FFExhTwNr43zWmfdg==\"\r\n");
	delay_ms(1000);
	_LCD_Show4GBUF(_4G_BUF,Rx_p);
	
	Rx_p=0;
	printf("AT+TCMQTTCONN=1,20000,240,1,1\r\n");
	delay_ms(1000);
	_LCD_Show4GBUF(_4G_BUF,Rx_p);
	
	Rx_p=0;
	printf("AT+TCMQTTSUB=\"$thing/down/property/5DOXOMOIXC/device1\",1\r\n");
	delay_ms(1000);
	_LCD_Show4GBUF(_4G_BUF,Rx_p);
}


/* 
 *��������:void L610_SendData(char * Addr,char * Data)
 *��������:���Ʒ�����Addr��ַ��������Data
 *�������:��
 *�������:��
 */
void L610_SendData(char * Addr,char * Data)
{
	printf("AT+TCMQTTPUB=\"$thing/up/property/5DOXOMOIXC/device1\",1,\"{\\\"method\\\":\\\"report\\\",\\\"clientToken\\\":\\\"123\\\",\\\"params\\\":{\\\"%s\\\":%s}}\"\r\n",Addr,Data);
	//printf("AT+TCMQTTPUB=\"$thing/up/property/IDODL7LU5L/Turbidity\",1,\"{\\\"method\\\":\\\"report\\\",\\\"clientToken\\\":\\\"123\\\",\\\"params\\\":{\\\"Turbidity2\\\":50.2}}\"\r\n");
	delay_ms(1000);
	_LCD_Show4GBUF(_4G_BUF,Rx_p);//��Ļ����
}



void USART1_IRQHandler(void)
{
	if (USART_GetITStatus(USART1, USART_IT_RXNE) == SET)
	{
		
		_4G_BUF[Rx_p]=USART_ReceiveData(USART1);
		
		Rx_p++;
		
		USART_ClearITPendingBit(USART1, USART_IT_RXNE);		
	}
}

