#include "LED.h"


/* 
 *��������:void LED_Init(void)
 *��������:LED���ó�ʼ��
 *�������:��
 *�������:��
 */
void LED_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	
	//����LED1�˿�ʱ��
	RCC_AHB1PeriphClockCmd(LED1_CLK,ENABLE);
	//����LED2�˿�ʱ��
	RCC_AHB1PeriphClockCmd(LED2_CLK,ENABLE);
	
	//����LED1����
	GPIO_InitStructure.GPIO_Pin=LED1_Pin;//ѡ��LED1����
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_OUT;//ѡ�����ģʽ
	GPIO_InitStructure.GPIO_OType=GPIO_OType_PP;//ѡ���������ģʽ
	GPIO_InitStructure.GPIO_PuPd=GPIO_PuPd_NOPULL;//ѡ����Ҫ������
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_100MHz;//ѡ��IO����ٶ�
	GPIO_Init(LED1_Port,&GPIO_InitStructure);
	
	//����LED2����
	GPIO_InitStructure.GPIO_Pin=LED2_Pin;//ѡ��LED2����
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_OUT;//ѡ�����ģʽ
	GPIO_InitStructure.GPIO_OType=GPIO_OType_PP;//ѡ���������ģʽ
	GPIO_InitStructure.GPIO_PuPd=GPIO_PuPd_NOPULL;//ѡ����Ҫ������
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_100MHz;//ѡ��IO����ٶ�
	GPIO_Init(LED2_Port,&GPIO_InitStructure);
	
	GPIO_SetBits(LED1_Port,LED1_Pin);
	GPIO_SetBits(LED2_Port,LED2_Pin);
}


/* 
 *��������:void LED_Toggle(uint16_t LED_Pin
 *��������:LED״̬��ת
 *�������:LED����
 *�������:��
 */
void LED_Toggle(uint16_t LED_Pin)
{
	if(LED_Pin==LED1_Pin)GPIO_ToggleBits(LED1_Port,LED1_Pin);
	else if(LED_Pin==LED2_Pin)GPIO_ToggleBits(LED2_Port,LED2_Pin);
}
