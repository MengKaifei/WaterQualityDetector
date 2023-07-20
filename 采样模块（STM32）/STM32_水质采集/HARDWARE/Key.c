#include "Key.h"


/* 
 *函数名称:void Key_Init(void)
 *函数功能:按键配置初始化
 *输入变量:无
 *输出变量:无
 */
void Key_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	
	//开启KEY1-3的外设时钟
	RCC_AHB1PeriphClockCmd(KEY_1_CLK,ENABLE);
	RCC_AHB1PeriphClockCmd(KEY_2_CLK,ENABLE);
	RCC_AHB1PeriphClockCmd(KEY_3_CLK,ENABLE);
	
	
	GPIO_InitStructure.GPIO_Pin=KEY_1_Pin;//选择KEY1_Pin
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_IN;//选择输入1模式
	GPIO_InitStructure.GPIO_PuPd=GPIO_PuPd_UP;//选择上拉
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_100MHz;//选择速度
	GPIO_Init(KEY_1_Port,&GPIO_InitStructure);
	
	GPIO_InitStructure.GPIO_Pin=KEY_2_Pin;//选择KEY2_Pin
	GPIO_Init(KEY_2_Port,&GPIO_InitStructure);
	
	GPIO_InitStructure.GPIO_Pin=KEY_3_Pin;//选择KEY3_Pin
	GPIO_Init(KEY_3_Port,&GPIO_InitStructure);
	
	
}


/* 
 *函数名称:uint8_t Key_Scan(void)
 *函数功能:按键扫描
 *输入变量:无
 *输出变量:按键值
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
