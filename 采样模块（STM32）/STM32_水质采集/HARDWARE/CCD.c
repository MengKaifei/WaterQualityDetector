#include "stm32f4xx.h"                  // Device header
#include "Delay.h"
#include "Adc.h"
void PWM_TIM2_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;
	TIM_OCInitTypeDef  TIM_OCInitStructure;
	
	//����LED1�˿�ʱ��
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA,ENABLE);
	//������ʱ��2ʱ��48HMz
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2,ENABLE);
	
	
	//����LED1����
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_1;//ѡ��LED1����
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_AF;//ѡ�����ģʽ
	GPIO_InitStructure.GPIO_OType=GPIO_OType_PP;//ѡ���������ģʽ
	GPIO_InitStructure.GPIO_PuPd=GPIO_PuPd_UP;//ѡ������
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_100MHz;//ѡ��IO����ٶ�
	GPIO_Init(GPIOA,&GPIO_InitStructure);
	/* Connect TIM3 pins to AF2 */  
	GPIO_PinAFConfig(GPIOA, GPIO_PinSource1, GPIO_AF_TIM2);

	//APB1 ����������Ƶ��Ϊ 42 MHz
    //APB2 ����������Ƶ��Ϊ 84 MHz
	//���ڶ�ʱ����� APB Ԥ��Ƶ��Ϊ 1����ʱ��ʱ��Ƶ�ʵ��� APB ���Ƶ�ʡ�
	//���򣬵��� APB ���Ƶ�ʵ����� (��2)
	TIM_TimeBaseStructure.TIM_Prescaler=1-1;//���ﶨʱ��Ƶ�ʣ�84000000/8400=100kHz
	TIM_TimeBaseStructure.TIM_Period=42-1;//2MHz;
	//TIM_TimeBaseStructure.TIM_ClockDivision=TIM_CKD_DIV1;//F407û������Ĵ���
	TIM_TimeBaseStructure.TIM_CounterMode=TIM_CounterMode_Up;//���ϼ���ģʽ
	//TIM_TimeBaseStructure.TIM_RepetitionCounter=0;//��ʱ��1�Ͷ�ʱ��8�ظ�����ֵ
	
	TIM_TimeBaseInit(TIM2, &TIM_TimeBaseStructure);
	

	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
	TIM_OCInitStructure.TIM_Pulse = 21;
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_Low;

	TIM_OC2Init(TIM2, &TIM_OCInitStructure);
 	TIM_OC2PreloadConfig(TIM2, TIM_OCPreload_Enable);  //ʹ��TIM2��CCR1�ϵ�Ԥװ�ؼĴ���
    TIM_ARRPreloadConfig(TIM2,ENABLE);//ARPEʹ�� 
	
//	/* ѡ������ģʽ*/
//	TIM_SelectMasterSlaveMode(TIM2, TIM_MasterSlaveMode_Enable);

//	/* ��ģʽѡ�� */
//	TIM_SelectOutputTrigger(TIM2, TIM_TRGOSource_Update);

	TIM_Cmd(TIM2,ENABLE);//������ʱ��
	
}

void PWM_TIM3_Init(void)//SH
{
	GPIO_InitTypeDef GPIO_InitStructure;
	TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;
	TIM_OCInitTypeDef  TIM_OCInitStructure;
	
	//����GPIO�˿�ʱ��
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA,ENABLE);
	//������ʱ��2ʱ��48HMz
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3,ENABLE);
	
	
	//����GPIO����
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_6;//ѡ��LED1����
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_AF;//ѡ�����ģʽ
	GPIO_InitStructure.GPIO_OType=GPIO_OType_PP;//ѡ���������ģʽ
	GPIO_InitStructure.GPIO_PuPd=GPIO_PuPd_UP;//ѡ������
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_100MHz;//ѡ��IO����ٶ�
	GPIO_Init(GPIOA,&GPIO_InitStructure);
	/* Connect TIM3 pins to AF2 */  
	GPIO_PinAFConfig(GPIOA, GPIO_PinSource6, GPIO_AF_TIM3);

	//APB1 ����������Ƶ��Ϊ 42 MHz
    //APB2 ����������Ƶ��Ϊ 84 MHz
	//���ڶ�ʱ����� APB Ԥ��Ƶ��Ϊ 1����ʱ��ʱ��Ƶ�ʵ��� APB ���Ƶ�ʡ�
	//���򣬵��� APB ���Ƶ�ʵ����� (��2)
	TIM_TimeBaseStructure.TIM_Prescaler=1-1;//���ﶨʱ��Ƶ�ʣ�84000000kHz
	TIM_TimeBaseStructure.TIM_Period=478-1;//4us;336+42+100
	//TIM_TimeBaseStructure.TIM_ClockDivision=TIM_CKD_DIV1;//F407û������Ĵ���
	TIM_TimeBaseStructure.TIM_CounterMode=TIM_CounterMode_Up;//���ϼ���ģʽ
	//TIM_TimeBaseStructure.TIM_RepetitionCounter=0;//��ʱ��1�Ͷ�ʱ��8�ظ�����ֵ
	
	TIM_TimeBaseInit(TIM3, &TIM_TimeBaseStructure);
	

	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
	TIM_OCInitStructure.TIM_Pulse = 142;
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_Low;

	TIM_OC1Init(TIM3, &TIM_OCInitStructure);
//	TIM_OC1PreloadConfig(TIM3, TIM_OCPreload_Enable);  //ʹ��TIM2��CCR1�ϵ�Ԥװ�ؼĴ���
//  TIM_ARRPreloadConfig(TIM3,ENABLE);//ARPEʹ�� 
	
	TIM_SelectOnePulseMode(TIM3, TIM_OPMode_Single);
	/* ��ģʽѡ��: TIM3 */
//	TIM_SelectSlaveMode(TIM3, TIM_SlaveMode_Gated);
//	TIM_SelectInputTrigger(TIM3, TIM_TS_ITR1);
	
	TIM_Cmd(TIM3,ENABLE);//������ʱ��
}

void PWM_TIM4_Init(void)//ICG
{
	GPIO_InitTypeDef GPIO_InitStructure;
	TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;
	TIM_OCInitTypeDef  TIM_OCInitStructure;
	
	//����GPIO�˿�ʱ��
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB,ENABLE);
	//������ʱ��2ʱ��48HMz
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4,ENABLE);
	
	
	//����LED1����
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_6;//ѡ��LED1����
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_AF;//ѡ�����ģʽ
	GPIO_InitStructure.GPIO_OType=GPIO_OType_PP;//ѡ���������ģʽ
	GPIO_InitStructure.GPIO_PuPd=GPIO_PuPd_UP;//ѡ������
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_100MHz;//ѡ��IO����ٶ�
	GPIO_Init(GPIOB,&GPIO_InitStructure);
	/* Connect TIM3 pins to AF2 */  
	GPIO_PinAFConfig(GPIOB, GPIO_PinSource6, GPIO_AF_TIM4);

	//APB1 ����������Ƶ��Ϊ 42 MHz
    //APB2 ����������Ƶ��Ϊ 84 MHz
	//���ڶ�ʱ����� APB Ԥ��Ƶ��Ϊ 1����ʱ��ʱ��Ƶ�ʵ��� APB ���Ƶ�ʡ�
	//���򣬵��� APB ���Ƶ�ʵ����� (��2)
	TIM_TimeBaseStructure.TIM_Prescaler=1-1;//���ﶨʱ��Ƶ�ʣ�84000000Hz
	TIM_TimeBaseStructure.TIM_Period=856-1;//756+100
	//TIM_TimeBaseStructure.TIM_ClockDivision=TIM_CKD_DIV1;//F407û������Ĵ���
	TIM_TimeBaseStructure.TIM_CounterMode=TIM_CounterMode_Up;//���ϼ���ģʽ
	//TIM_TimeBaseStructure.TIM_RepetitionCounter=0;//��ʱ��1�Ͷ�ʱ��8�ظ�����ֵ
	
	TIM_TimeBaseInit(TIM4, &TIM_TimeBaseStructure);
	

	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
	TIM_OCInitStructure.TIM_Pulse = 100;
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;

	TIM_OC1Init(TIM4, &TIM_OCInitStructure);
//	TIM_OC1PreloadConfig(TIM4, TIM_OCPreload_Enable);  //ʹ��TIM2��CCR1�ϵ�Ԥװ�ؼĴ���
//  TIM_ARRPreloadConfig(TIM4,ENABLE);//ARPEʹ�� 
	
	//������ģʽ
	TIM_SelectOnePulseMode(TIM4, TIM_OPMode_Single);
	 /* ��ģʽѡ��: TIM4 */
//	TIM_SelectSlaveMode(TIM4, TIM_SlaveMode_Gated);
//	TIM_SelectInputTrigger(TIM4, TIM_TS_ITR1);
	
	TIM_Cmd(TIM4,ENABLE);//������ʱ��
}


void PWM_TIM5_Init(void)//ADC
{
	GPIO_InitTypeDef GPIO_InitStructure;
	TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;
	TIM_OCInitTypeDef  TIM_OCInitStructure;
	
	//������ʱ��2ʱ��48HMz
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM5,ENABLE);
	
	
	//����GPIO����
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_0;//ѡ������
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_AF;//ѡ�����ģʽ
	GPIO_InitStructure.GPIO_OType=GPIO_OType_PP;//ѡ���������ģʽ
	GPIO_InitStructure.GPIO_PuPd=GPIO_PuPd_UP;//ѡ������
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_100MHz;//ѡ��IO����ٶ�
	GPIO_Init(GPIOA,&GPIO_InitStructure);
	/* Connect TIM3 pins to AF2 */  
	GPIO_PinAFConfig(GPIOA, GPIO_PinSource0, GPIO_AF_TIM5);

	//APB1 ����������Ƶ��Ϊ 42 MHz
    //APB2 ����������Ƶ��Ϊ 84 MHz
	//���ڶ�ʱ����� APB Ԥ��Ƶ��Ϊ 1����ʱ��ʱ��Ƶ�ʵ��� APB ���Ƶ�ʡ�
	//���򣬵��� APB ���Ƶ�ʵ����� (��2)
	TIM_TimeBaseStructure.TIM_Prescaler=42-1;//���ﶨʱ��Ƶ�ʣ�84000000Hz
	TIM_TimeBaseStructure.TIM_Period=8-1;//756+100
	//TIM_TimeBaseStructure.TIM_ClockDivision=TIM_CKD_DIV1;//F407û������Ĵ���
	TIM_TimeBaseStructure.TIM_CounterMode=TIM_CounterMode_Up;//���ϼ���ģʽ
	//TIM_TimeBaseStructure.TIM_RepetitionCounter=0;//��ʱ��1�Ͷ�ʱ��8�ظ�����ֵ
	
	TIM_TimeBaseInit(TIM5, &TIM_TimeBaseStructure);
	

	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
	TIM_OCInitStructure.TIM_Pulse = 4;
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;

	TIM_OC1Init(TIM5, &TIM_OCInitStructure);
	TIM_Cmd(TIM5,ENABLE);//������ʱ��
}



void CCD_Init(void)
{
	PWM_TIM2_Init();//&M
	PWM_TIM3_Init();//SH
	PWM_TIM4_Init();//ICG
	PWM_TIM5_Init();//ADC
	
}

void CCD_Read(void)
{
	Adc1_Init();
	TIM_Cmd(TIM3,ENABLE);//������ʱ��
	TIM_Cmd(TIM4,ENABLE);//������ʱ��
}