#include "Key.h"


/* 
 *��������:void Key_Init(void)
 *��������:�������ó�ʼ��
 *�������:��
 *�������:��
 */
void Key_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	
	//����KEY1-3������ʱ��
	RCC_AHB1PeriphClockCmd(KEY_1_CLK,ENABLE);
	RCC_AHB1PeriphClockCmd(KEY_2_CLK,ENABLE);
	RCC_AHB1PeriphClockCmd(KEY_3_CLK,ENABLE);
	
	
	GPIO_InitStructure.GPIO_Pin=KEY_1_Pin;//ѡ��KEY1_Pin
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_IN;//ѡ������1ģʽ
	GPIO_InitStructure.GPIO_PuPd=GPIO_PuPd_UP;//ѡ������
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_100MHz;//ѡ���ٶ�
	GPIO_Init(KEY_1_Port,&GPIO_InitStructure);
	
	GPIO_InitStructure.GPIO_Pin=KEY_2_Pin;//ѡ��KEY2_Pin
	GPIO_Init(KEY_2_Port,&GPIO_InitStructure);
	
	GPIO_InitStructure.GPIO_Pin=KEY_3_Pin;//ѡ��KEY3_Pin
	GPIO_Init(KEY_3_Port,&GPIO_InitStructure);
	
	
}


/* 
 *��������:uint8_t Key_Scan(void)
 *��������:����ɨ��
 *�������:��
 *�������:����ֵ
 */
uint8_t Key_Scan(void)
{
	if(KEY_1==0)
	{
		delay_ms(20);
		if(KEY_1==0)while(KEY_1==0);
		delay_ms(20);
		return 1;
	}
	
	if(KEY_2==0)
	{
		delay_ms(20);
		if(KEY_2==0)while(KEY_2==0);
		delay_ms(20);
		return 2;
	}
	
	if(KEY_3==0)
	{
		delay_ms(20);
		if(KEY_3==0)while(KEY_3==0);
		delay_ms(20);
		return 3;
	}
	
	
	return 0;
}
