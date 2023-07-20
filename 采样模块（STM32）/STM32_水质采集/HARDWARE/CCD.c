#include "stm32f4xx.h"                  // Device header
#include "Delay.h"
#include "Adc.h"
void PWM_TIM2_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;
	TIM_OCInitTypeDef  TIM_OCInitStructure;
	
	//开启LED1端口时钟
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA,ENABLE);
	//开启定时器2时钟48HMz
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2,ENABLE);
	
	
	//配置LED1引脚
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_1;//选择LED1引脚
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_AF;//选择输出模式
	GPIO_InitStructure.GPIO_OType=GPIO_OType_PP;//选择推挽输出模式
	GPIO_InitStructure.GPIO_PuPd=GPIO_PuPd_UP;//选择上拉
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_100MHz;//选择IO输出速度
	GPIO_Init(GPIOA,&GPIO_InitStructure);
	/* Connect TIM3 pins to AF2 */  
	GPIO_PinAFConfig(GPIOA, GPIO_PinSource1, GPIO_AF_TIM2);

	//APB1 域的最大允许频率为 42 MHz
    //APB2 域的最大允许频率为 84 MHz
	//对于定时器如果 APB 预分频器为 1，定时器时钟频率等于 APB 域的频率。
	//否则，等于 APB 域的频率的两倍 (×2)
	TIM_TimeBaseStructure.TIM_Prescaler=1-1;//到达定时器频率：84000000/8400=100kHz
	TIM_TimeBaseStructure.TIM_Period=42-1;//2MHz;
	//TIM_TimeBaseStructure.TIM_ClockDivision=TIM_CKD_DIV1;//F407没有这个寄存器
	TIM_TimeBaseStructure.TIM_CounterMode=TIM_CounterMode_Up;//向上计数模式
	//TIM_TimeBaseStructure.TIM_RepetitionCounter=0;//定时器1和定时器8重复计数值
	
	TIM_TimeBaseInit(TIM2, &TIM_TimeBaseStructure);
	

	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
	TIM_OCInitStructure.TIM_Pulse = 21;
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_Low;

	TIM_OC2Init(TIM2, &TIM_OCInitStructure);
 	TIM_OC2PreloadConfig(TIM2, TIM_OCPreload_Enable);  //使能TIM2在CCR1上的预装载寄存器
    TIM_ARRPreloadConfig(TIM2,ENABLE);//ARPE使能 
	
//	/* 选择主从模式*/
//	TIM_SelectMasterSlaveMode(TIM2, TIM_MasterSlaveMode_Enable);

//	/* 主模式选择 */
//	TIM_SelectOutputTrigger(TIM2, TIM_TRGOSource_Update);

	TIM_Cmd(TIM2,ENABLE);//开启定时器
	
}

void PWM_TIM3_Init(void)//SH
{
	GPIO_InitTypeDef GPIO_InitStructure;
	TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;
	TIM_OCInitTypeDef  TIM_OCInitStructure;
	
	//开启GPIO端口时钟
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA,ENABLE);
	//开启定时器2时钟48HMz
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3,ENABLE);
	
	
	//配置GPIO引脚
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_6;//选择LED1引脚
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_AF;//选择输出模式
	GPIO_InitStructure.GPIO_OType=GPIO_OType_PP;//选择推挽输出模式
	GPIO_InitStructure.GPIO_PuPd=GPIO_PuPd_UP;//选择上拉
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_100MHz;//选择IO输出速度
	GPIO_Init(GPIOA,&GPIO_InitStructure);
	/* Connect TIM3 pins to AF2 */  
	GPIO_PinAFConfig(GPIOA, GPIO_PinSource6, GPIO_AF_TIM3);

	//APB1 域的最大允许频率为 42 MHz
    //APB2 域的最大允许频率为 84 MHz
	//对于定时器如果 APB 预分频器为 1，定时器时钟频率等于 APB 域的频率。
	//否则，等于 APB 域的频率的两倍 (×2)
	TIM_TimeBaseStructure.TIM_Prescaler=1-1;//到达定时器频率：84000000kHz
	TIM_TimeBaseStructure.TIM_Period=478-1;//4us;336+42+100
	//TIM_TimeBaseStructure.TIM_ClockDivision=TIM_CKD_DIV1;//F407没有这个寄存器
	TIM_TimeBaseStructure.TIM_CounterMode=TIM_CounterMode_Up;//向上计数模式
	//TIM_TimeBaseStructure.TIM_RepetitionCounter=0;//定时器1和定时器8重复计数值
	
	TIM_TimeBaseInit(TIM3, &TIM_TimeBaseStructure);
	

	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
	TIM_OCInitStructure.TIM_Pulse = 142;
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_Low;

	TIM_OC1Init(TIM3, &TIM_OCInitStructure);
//	TIM_OC1PreloadConfig(TIM3, TIM_OCPreload_Enable);  //使能TIM2在CCR1上的预装载寄存器
//  TIM_ARRPreloadConfig(TIM3,ENABLE);//ARPE使能 
	
	TIM_SelectOnePulseMode(TIM3, TIM_OPMode_Single);
	/* 从模式选择: TIM3 */
//	TIM_SelectSlaveMode(TIM3, TIM_SlaveMode_Gated);
//	TIM_SelectInputTrigger(TIM3, TIM_TS_ITR1);
	
	TIM_Cmd(TIM3,ENABLE);//开启定时器
}

void PWM_TIM4_Init(void)//ICG
{
	GPIO_InitTypeDef GPIO_InitStructure;
	TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;
	TIM_OCInitTypeDef  TIM_OCInitStructure;
	
	//开启GPIO端口时钟
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB,ENABLE);
	//开启定时器2时钟48HMz
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4,ENABLE);
	
	
	//配置LED1引脚
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_6;//选择LED1引脚
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_AF;//选择输出模式
	GPIO_InitStructure.GPIO_OType=GPIO_OType_PP;//选择推挽输出模式
	GPIO_InitStructure.GPIO_PuPd=GPIO_PuPd_UP;//选择上拉
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_100MHz;//选择IO输出速度
	GPIO_Init(GPIOB,&GPIO_InitStructure);
	/* Connect TIM3 pins to AF2 */  
	GPIO_PinAFConfig(GPIOB, GPIO_PinSource6, GPIO_AF_TIM4);

	//APB1 域的最大允许频率为 42 MHz
    //APB2 域的最大允许频率为 84 MHz
	//对于定时器如果 APB 预分频器为 1，定时器时钟频率等于 APB 域的频率。
	//否则，等于 APB 域的频率的两倍 (×2)
	TIM_TimeBaseStructure.TIM_Prescaler=1-1;//到达定时器频率：84000000Hz
	TIM_TimeBaseStructure.TIM_Period=856-1;//756+100
	//TIM_TimeBaseStructure.TIM_ClockDivision=TIM_CKD_DIV1;//F407没有这个寄存器
	TIM_TimeBaseStructure.TIM_CounterMode=TIM_CounterMode_Up;//向上计数模式
	//TIM_TimeBaseStructure.TIM_RepetitionCounter=0;//定时器1和定时器8重复计数值
	
	TIM_TimeBaseInit(TIM4, &TIM_TimeBaseStructure);
	

	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
	TIM_OCInitStructure.TIM_Pulse = 100;
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;

	TIM_OC1Init(TIM4, &TIM_OCInitStructure);
//	TIM_OC1PreloadConfig(TIM4, TIM_OCPreload_Enable);  //使能TIM2在CCR1上的预装载寄存器
//  TIM_ARRPreloadConfig(TIM4,ENABLE);//ARPE使能 
	
	//单周期模式
	TIM_SelectOnePulseMode(TIM4, TIM_OPMode_Single);
	 /* 从模式选择: TIM4 */
//	TIM_SelectSlaveMode(TIM4, TIM_SlaveMode_Gated);
//	TIM_SelectInputTrigger(TIM4, TIM_TS_ITR1);
	
	TIM_Cmd(TIM4,ENABLE);//开启定时器
}


void PWM_TIM5_Init(void)//ADC
{
	GPIO_InitTypeDef GPIO_InitStructure;
	TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;
	TIM_OCInitTypeDef  TIM_OCInitStructure;
	
	//开启定时器2时钟48HMz
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM5,ENABLE);
	
	
	//配置GPIO引脚
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_0;//选择引脚
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_AF;//选择输出模式
	GPIO_InitStructure.GPIO_OType=GPIO_OType_PP;//选择推挽输出模式
	GPIO_InitStructure.GPIO_PuPd=GPIO_PuPd_UP;//选择上拉
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_100MHz;//选择IO输出速度
	GPIO_Init(GPIOA,&GPIO_InitStructure);
	/* Connect TIM3 pins to AF2 */  
	GPIO_PinAFConfig(GPIOA, GPIO_PinSource0, GPIO_AF_TIM5);

	//APB1 域的最大允许频率为 42 MHz
    //APB2 域的最大允许频率为 84 MHz
	//对于定时器如果 APB 预分频器为 1，定时器时钟频率等于 APB 域的频率。
	//否则，等于 APB 域的频率的两倍 (×2)
	TIM_TimeBaseStructure.TIM_Prescaler=42-1;//到达定时器频率：84000000Hz
	TIM_TimeBaseStructure.TIM_Period=8-1;//756+100
	//TIM_TimeBaseStructure.TIM_ClockDivision=TIM_CKD_DIV1;//F407没有这个寄存器
	TIM_TimeBaseStructure.TIM_CounterMode=TIM_CounterMode_Up;//向上计数模式
	//TIM_TimeBaseStructure.TIM_RepetitionCounter=0;//定时器1和定时器8重复计数值
	
	TIM_TimeBaseInit(TIM5, &TIM_TimeBaseStructure);
	

	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
	TIM_OCInitStructure.TIM_Pulse = 4;
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;

	TIM_OC1Init(TIM5, &TIM_OCInitStructure);
	TIM_Cmd(TIM5,ENABLE);//开启定时器
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
	TIM_Cmd(TIM3,ENABLE);//开启定时器
	TIM_Cmd(TIM4,ENABLE);//开启定时器
}