#include "Serial.h"                

uint8_t USART2_BUF[8];
uint8_t Pack_Finish=0;
/* 
 *��������:void Serial_Init(void)
 *��������:���ڳ�ʹ��
 *�������:��
 *�������:��
 */
void Serial_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	USART_InitTypeDef USART_InitStructure;
	NVIC_InitTypeDef NVIC_InitStructure;
   
	//����GPIOAʱ��
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA,ENABLE);
	//����USART1ʱ��
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1,ENABLE);
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9|GPIO_Pin_10;//ѡ��GPIO_Pin_9��GPIO_Pin_10����
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;//ѡ����ģʽ
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;//ѡ������ٶ�
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;//ѡ���������
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;//ѡ������
	GPIO_Init(GPIOA, &GPIO_InitStructure);//��ʼ������
	
	/* Connect USART pins to AF9 */
	GPIO_PinAFConfig(GPIOA, GPIO_PinSource9, GPIO_AF_USART1);
	/* Connect USART pins to AF10 */
	GPIO_PinAFConfig(GPIOA, GPIO_PinSource10, GPIO_AF_USART1);
	
	
	USART_InitStructure.USART_BaudRate = 115200;//ѡ������
	USART_InitStructure.USART_WordLength = USART_WordLength_8b;//ѡ��8λ���ݿ��
	USART_InitStructure.USART_StopBits = USART_StopBits_1;//ѡ��ֹͣλΪһλ
	USART_InitStructure.USART_Parity = USART_Parity_No;//У��λλ0
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;//������
	USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;//ģʽΪ�շ�
	USART_Init(USART1, &USART_InitStructure);
	
	NVIC_InitStructure.NVIC_IRQChannel = USART1_IRQn;//ѡ���ж�ͨ��
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;//������ռ���ȼ�
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;//������Ӧ���ȼ�
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;//ʹ��
	NVIC_Init(&NVIC_InitStructure);
	
	USART_ITConfig(USART1, USART_IT_RXNE, ENABLE);//���ý����ж�
	
	USART_Cmd(USART1,ENABLE);//��������
}

/* 
 *��������:void Serial_SendByte(uint8_t Byte)
 *��������:���ڷ���һ���ֽ�����
 *�������:Ҫ���͵�16��������
 *�������:��
 */
void Serial_SendByte(uint8_t Byte)
{
	USART_SendData(USART1, Byte);
	while (USART_GetFlagStatus(USART1, USART_FLAG_TXE) == RESET);
}


/* 
 *��������:int fputc(int ch, FILE *f)
 *��������:�����ض���
 *�������:int ch, FILE *f
 *�������:��
 */
int fputc(int ch, FILE *f)
{
	USART_SendData(USART1, ch);
	while (USART_GetFlagStatus(USART1, USART_FLAG_TXE) == RESET);
	return ch;
}


/* 
 *��������:void USART2_Init(void)
 *��������:���ڳ�ʹ��
 *�������:��
 *�������:��
 */
void USART2_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	USART_InitTypeDef USART_InitStructure;
	NVIC_InitTypeDef NVIC_InitStructure;
   
	//����GPIOAʱ��
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA,ENABLE);
	//����USART1ʱ��
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART2,ENABLE);
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2|GPIO_Pin_3;//ѡ��GPIO_Pin_9��GPIO_Pin_10����
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;//ѡ����ģʽ
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;//ѡ������ٶ�
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;//ѡ���������
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;//ѡ������
	GPIO_Init(GPIOA, &GPIO_InitStructure);//��ʼ������
	
	/* Connect USART pins to AF9 */
	GPIO_PinAFConfig(GPIOA, GPIO_PinSource2, GPIO_AF_USART2);
	/* Connect USART pins to AF10 */
	GPIO_PinAFConfig(GPIOA, GPIO_PinSource3, GPIO_AF_USART2);
	
	
	USART_InitStructure.USART_BaudRate = 115200;//ѡ������
	USART_InitStructure.USART_WordLength = USART_WordLength_8b;//ѡ��8λ���ݿ��
	USART_InitStructure.USART_StopBits = USART_StopBits_1;//ѡ��ֹͣλΪһλ
	USART_InitStructure.USART_Parity = USART_Parity_No;//У��λλ0
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;//������
	USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;//ģʽΪ�շ�
	USART_Init(USART2, &USART_InitStructure);
	
	NVIC_InitStructure.NVIC_IRQChannel = USART2_IRQn;//ѡ���ж�ͨ��
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;//������ռ���ȼ�
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;//������Ӧ���ȼ�
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;//ʹ��
	NVIC_Init(&NVIC_InitStructure);
	
	USART_ITConfig(USART2, USART_IT_RXNE, ENABLE);//���ý����ж�
	
	USART_Cmd(USART2,ENABLE);//��������
}


/* 
 *��������:void USART2_SendByte(uint8_t Byte)
 *��������:���ڷ���һ���ֽ�����
 *�������:Ҫ���͵�16��������
 *�������:��
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
		if(Pack_Finish==0)//�����־�����½�������
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
