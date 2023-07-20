#include "TIM.h"                  // Device header

/* 
 *��������:void TIM_Init(void)
 *��������:��ʱ�����ó�ʼ��
 *�������:��
 *�������:��
 */
void TIM_Init(void)
{
	NVIC_InitTypeDef NVIC_InitStructure;

	TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;
	
	//������ʱ��2ʱ��48HMz
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM1,ENABLE);
	
	NVIC_InitStructure.NVIC_IRQChannel=TIM1_UP_TIM10_IRQn;//ѡ��ͨ��
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=2;//������ռ���ȼ�
	NVIC_InitStructure.NVIC_IRQChannelSubPriority=2;//������Ӧ���ȼ�
	NVIC_InitStructure.NVIC_IRQChannelCmd=ENABLE;//ʹ��
	NVIC_Init(&NVIC_InitStructure);
				                              //���ڶ�ʱ����� APB Ԥ��Ƶ��Ϊ 1����ʱ��ʱ��Ƶ�ʵ��� APB ���Ƶ�ʡ�
		                                      //���򣬵��� APB ���Ƶ�ʵ����� (��2)
	TIM_TimeBaseStructure.TIM_Prescaler=16800-1;//Ԥ��Ƶ��ֵ��Ƶ84000000/84000����1000Hz
	TIM_TimeBaseStructure.TIM_Period=5000-1;//500ms
	//TIM_TimeBaseStructure.TIM_ClockDivision=TIM_CKD_DIV1;//F407û������Ĵ���
	TIM_TimeBaseStructure.TIM_CounterMode=TIM_CounterMode_Up;//���ϼ���ģʽ
	TIM_TimeBaseStructure.TIM_RepetitionCounter=0;//��ʱ��1�Ͷ�ʱ��8�ظ�����ֵ
	
	TIM_TimeBaseInit(TIM1, &TIM_TimeBaseStructure);
	
	TIM_ITConfig(TIM1,TIM_IT_Update, ENABLE);//ʹ�ܶ�ʱ���ж�

	TIM_Cmd(TIM1,ENABLE);//������ʱ��
}
