#include "LED.h"


/* 
 *函数名称:void LED_Init(void)
 *函数功能:LED配置初始化
 *输入变量:无
 *输出变量:无
 */
void LED_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	
	//开启LED1端口时钟
	RCC_AHB1PeriphClockCmd(LED1_CLK,ENABLE);
	//开启LED2端口时钟
	RCC_AHB1PeriphClockCmd(LED2_CLK,ENABLE);
	
	//配置LED1引脚
	GPIO_InitStructure.GPIO_Pin=LED1_Pin;//选择LED1引脚
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_OUT;//选择输出模式
	GPIO_InitStructure.GPIO_OType=GPIO_OType_PP;//选择推挽输出模式
	GPIO_InitStructure.GPIO_PuPd=GPIO_PuPd_NOPULL;//选择不需要上下拉
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_100MHz;//选择IO输出速度
	GPIO_Init(LED1_Port,&GPIO_InitStructure);
	
	//配置LED2引脚
	GPIO_InitStructure.GPIO_Pin=LED2_Pin;//选择LED2引脚
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_OUT;//选择输出模式
	GPIO_InitStructure.GPIO_OType=GPIO_OType_PP;//选择推挽输出模式
	GPIO_InitStructure.GPIO_PuPd=GPIO_PuPd_NOPULL;//选择不需要上下拉
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_100MHz;//选择IO输出速度
	GPIO_Init(LED2_Port,&GPIO_InitStructure);
	
	GPIO_SetBits(LED1_Port,LED1_Pin);
	GPIO_SetBits(LED2_Port,LED2_Pin);
}


/* 
 *函数名称:void LED_Toggle(uint16_t LED_Pin
 *函数功能:LED状态翻转
 *输入变量:LED引脚
 *输出变量:无
 */
void LED_Toggle(uint16_t LED_Pin)
{
	if(LED_Pin==LED1_Pin)GPIO_ToggleBits(LED1_Port,LED1_Pin);
	else if(LED_Pin==LED2_Pin)GPIO_ToggleBits(LED2_Port,LED2_Pin);
}
