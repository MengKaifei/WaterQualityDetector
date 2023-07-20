#include "TIM.h"                  // Device header

/* 
 *函数名称:void TIM_Init(void)
 *函数功能:定时器配置初始化
 *输入变量:无
 *输出变量:无
 */
void TIM_Init(void)
{
	NVIC_InitTypeDef NVIC_InitStructure;

	TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;
	
	//开启定时器2时钟48HMz
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM1,ENABLE);
	
	NVIC_InitStructure.NVIC_IRQChannel=TIM1_UP_TIM10_IRQn;//选择通道
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=2;//配置抢占优先级
	NVIC_InitStructure.NVIC_IRQChannelSubPriority=2;//配置响应优先级
	NVIC_InitStructure.NVIC_IRQChannelCmd=ENABLE;//使能
	NVIC_Init(&NVIC_InitStructure);
				                              //对于定时器如果 APB 预分频器为 1，定时器时钟频率等于 APB 域的频率。
		                                      //否则，等于 APB 域的频率的两倍 (×2)
	TIM_TimeBaseStructure.TIM_Prescaler=16800-1;//预分频器值分频84000000/84000，即1000Hz
	TIM_TimeBaseStructure.TIM_Period=5000-1;//500ms
	//TIM_TimeBaseStructure.TIM_ClockDivision=TIM_CKD_DIV1;//F407没有这个寄存器
	TIM_TimeBaseStructure.TIM_CounterMode=TIM_CounterMode_Up;//向上计数模式
	TIM_TimeBaseStructure.TIM_RepetitionCounter=0;//定时器1和定时器8重复计数值
	
	TIM_TimeBaseInit(TIM1, &TIM_TimeBaseStructure);
	
	TIM_ITConfig(TIM1,TIM_IT_Update, ENABLE);//使能定时器中断

	TIM_Cmd(TIM1,ENABLE);//开启定时器
}
