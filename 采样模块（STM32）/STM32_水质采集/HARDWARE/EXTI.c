#include "EXTI.h"                

#include "stm32f4xx_exti.h" 

/* 
 *��������:void GPIO_EXTI_Init(void)
 *��������:GPIO�ж�����
 *�������:��
 *�������:��
 */
void GPIO_EXTI_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	EXTI_InitTypeDef EXTI_InitStructure;
	NVIC_InitTypeDef NVIC_InitStructure;
	
	/* Enable GPIOE clock */
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOE,ENABLE);
	 /* Enable SYSCFG clock 
	ϵͳ���ÿ�������Ҫ���ڹ���Կ�ִ�д���Ĵ洢����ĵ�ַ��ӳ�䡢ѡ����̫�� PHY �� 
	���Լ�����  GPIO ���ⲿ�ж������ӡ�*/
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_SYSCFG,ENABLE);
	
	 /* Configure PE3-4 pin as input floating */
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_3|GPIO_Pin_4;
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_IN;
	GPIO_InitStructure.GPIO_PuPd=GPIO_PuPd_UP;
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_100MHz;
	GPIO_Init(GPIOE,&GPIO_InitStructure);
	
	 /* Connect EXTI Line0 to PE3 pin */
	SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOE,EXTI_PinSource3);
	 /* Connect EXTI Line0 to PE4 pin */
	SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOE,EXTI_PinSource4);
	
	EXTI_InitStructure.EXTI_Line = EXTI_Line3|EXTI_Line4;
	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Rising;  
	EXTI_InitStructure.EXTI_LineCmd = ENABLE;
	EXTI_Init(&EXTI_InitStructure);

	 /* Enable and set EXTI Line3 Interrupt to the lowest priority */
	NVIC_InitStructure.NVIC_IRQChannel = EXTI3_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure);
	
	 /* Enable and set EXTI Line4 Interrupt to the lowest priority */
	NVIC_InitStructure.NVIC_IRQChannel = EXTI4_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure);
	
}
