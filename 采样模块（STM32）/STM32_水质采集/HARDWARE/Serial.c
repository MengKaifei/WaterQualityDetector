#include "Serial.h"                

uint8_t USART2_BUF[8];
uint8_t Pack_Finish=0;
/* 
 *函数名称:void Serial_Init(void)
 *函数功能:串口初使化
 *输入变量:无
 *输出变量:无
 */
void Serial_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	USART_InitTypeDef USART_InitStructure;
	NVIC_InitTypeDef NVIC_InitStructure;
   
	//开启GPIOA时钟
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA,ENABLE);
	//开启USART1时钟
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1,ENABLE);
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9|GPIO_Pin_10;//选择GPIO_Pin_9和GPIO_Pin_10引脚
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;//选择复用模式
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;//选择输出速度
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;//选择推挽输出
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;//选择上拉
	GPIO_Init(GPIOA, &GPIO_InitStructure);//初始化引脚
	
	/* Connect USART pins to AF9 */
	GPIO_PinAFConfig(GPIOA, GPIO_PinSource9, GPIO_AF_USART1);
	/* Connect USART pins to AF10 */
	GPIO_PinAFConfig(GPIOA, GPIO_PinSource10, GPIO_AF_USART1);
	
	
	USART_InitStructure.USART_BaudRate = 115200;//选择波特率
	USART_InitStructure.USART_WordLength = USART_WordLength_8b;//选择8位数据宽度
	USART_InitStructure.USART_StopBits = USART_StopBits_1;//选择停止位为一位
	USART_InitStructure.USART_Parity = USART_Parity_No;//校验位位0
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;//无流控
	USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;//模式为收发
	USART_Init(USART1, &USART_InitStructure);
	
	NVIC_InitStructure.NVIC_IRQChannel = USART1_IRQn;//选择中断通道
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;//配置抢占优先级
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;//配置响应优先级
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;//使能
	NVIC_Init(&NVIC_InitStructure);
	
	USART_ITConfig(USART1, USART_IT_RXNE, ENABLE);//配置接收中断
	
	USART_Cmd(USART1,ENABLE);//开启串口
}

/* 
 *函数名称:void Serial_SendByte(uint8_t Byte)
 *函数功能:串口发送一个字节数据
 *输入变量:要发送的16进制数据
 *输出变量:无
 */
void Serial_SendByte(uint8_t Byte)
{
	USART_SendData(USART1, Byte);
	while (USART_GetFlagStatus(USART1, USART_FLAG_TXE) == RESET);
}


/* 
 *函数名称:int fputc(int ch, FILE *f)
 *函数功能:串口重定向
 *输入变量:int ch, FILE *f
 *输出变量:无
 */
int fputc(int ch, FILE *f)
{
	USART_SendData(USART1, ch);
	while (USART_GetFlagStatus(USART1, USART_FLAG_TXE) == RESET);
	return ch;
}


/* 
 *函数名称:void USART2_Init(void)
 *函数功能:串口初使化
 *输入变量:无
 *输出变量:无
 */
void USART2_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	USART_InitTypeDef USART_InitStructure;
	NVIC_InitTypeDef NVIC_InitStructure;
   
	//开启GPIOA时钟
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA,ENABLE);
	//开启USART1时钟
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART2,ENABLE);
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2|GPIO_Pin_3;//选择GPIO_Pin_9和GPIO_Pin_10引脚
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;//选择复用模式
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;//选择输出速度
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;//选择推挽输出
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;//选择上拉
	GPIO_Init(GPIOA, &GPIO_InitStructure);//初始化引脚
	
	/* Connect USART pins to AF9 */
	GPIO_PinAFConfig(GPIOA, GPIO_PinSource2, GPIO_AF_USART2);
	/* Connect USART pins to AF10 */
	GPIO_PinAFConfig(GPIOA, GPIO_PinSource3, GPIO_AF_USART2);
	
	
	USART_InitStructure.USART_BaudRate = 115200;//选择波特率
	USART_InitStructure.USART_WordLength = USART_WordLength_8b;//选择8位数据宽度
	USART_InitStructure.USART_StopBits = USART_StopBits_1;//选择停止位为一位
	USART_InitStructure.USART_Parity = USART_Parity_No;//校验位位0
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;//无流控
	USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;//模式为收发
	USART_Init(USART2, &USART_InitStructure);
	
	NVIC_InitStructure.NVIC_IRQChannel = USART2_IRQn;//选择中断通道
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;//配置抢占优先级
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;//配置响应优先级
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;//使能
	NVIC_Init(&NVIC_InitStructure);
	
	USART_ITConfig(USART2, USART_IT_RXNE, ENABLE);//配置接收中断
	
	USART_Cmd(USART2,ENABLE);//开启串口
}


/* 
 *函数名称:void USART2_SendByte(uint8_t Byte)
 *函数功能:串口发送一个字节数据
 *输入变量:要发送的16进制数据
 *输出变量:无
 */
void USART2_SendByte(uint8_t Byte)
{
	USART_SendData(USART2, Byte);
	while (USART_GetFlagStatus(USART2, USART_FLAG_TXE) == RESET);
}


void USART2_SendPack(uint8_t Command,uint16_t DATA1,uint16_t DATA2)
{
	uint8_t DATA_Temp[4];
	
	DATA_Temp[0]=(uint8_t)(DATA1>>8);
	DATA_Temp[1]=(uint8_t)(DATA1);
	DATA_Temp[2]=(uint8_t)(DATA2>>8);
	DATA_Temp[3]=(uint8_t)(DATA2);
	USART2_SendByte(0x5A);
	USART2_SendByte(Command);
	USART2_SendByte(DATA_Temp[0]);
	USART2_SendByte(DATA_Temp[1]);
	USART2_SendByte(DATA_Temp[2]);
	USART2_SendByte(DATA_Temp[3]);
	USART2_SendByte(0x5A^Command^DATA_Temp[0]^DATA_Temp[1]^DATA_Temp[2]^DATA_Temp[3]^0x5B);
	USART2_SendByte(0x5B);
}



uint8_t USART2_CheckPack(void)
{
	uint8_t Check_DATA;
	if(Pack_Finish==1)
	{
		
		Check_DATA=USART2_BUF[0]^USART2_BUF[1]^USART2_BUF[2]^USART2_BUF[3]^\
			   USART2_BUF[4]^USART2_BUF[5]^USART2_BUF[7];
	
		if(Check_DATA== USART2_BUF[6])
		{
			Pack_Finish=0;
			return 1;
		}
		Pack_Finish=0;
	}
	return 0;
}



void USART2_IRQHandler(void)
{
	static uint8_t   Pack_Steps=0;
	static uint8_t   p_Pack=0;
	
	uint8_t Serial_RxData;
	
	if (USART_GetITStatus(USART2, USART_IT_RXNE) == SET)
	{
		if(Pack_Finish==0)//清除标志再重新接收数据
		{
			Serial_RxData = USART_ReceiveData(USART2);
		
			if(Serial_RxData == 0x5A && Pack_Steps==0)
			{
				Pack_Steps=1;
			
				p_Pack=0;
				
			}
			if(Pack_Steps==1)
			{
				USART2_BUF[p_Pack]=Serial_RxData;
				p_Pack++;
			}
		
			if(USART2_BUF[7]==0x5B && p_Pack==8)
			{
				p_Pack=0;
				Pack_Steps=0;
				Pack_Finish=1;
			}
			else if(p_Pack>7)
			{
				p_Pack=0;
				Pack_Steps=0;
				
			}
		}
		USART_ClearITPendingBit(USART2, USART_IT_RXNE);		
	}
}
