#include "FLASH.h"                  // Device header
#include "LED.h"


/* 
 *��������:void FLASH_WriteU32tData(uint32_t Sector_Addr,uint32_t WriteAddr,uint32_t WriteData)
 *��������:��Flashд��1��32λ����
 *�������:Sector_Addr-������ʼ��ַ
 *�������:WriteAddr-������ַ�µ�ƫ��
 *�������:WriteData-Ҫд�������
 *�������:��
 */
void FLASH_WriteU32tData(uint32_t Sector_Addr,uint32_t WriteAddr,uint32_t WriteData)
{
	uint32_t p_WriteAddr=0;
	uint32_t p_EndAddr=0;
	//����FLASH ��ʹ�ܶ�FLASH���ƼĴ����ķ���
	FLASH_Unlock();
	//�������ı�־(�����)
	FLASH_ClearFlag(FLASH_FLAG_EOP | FLASH_FLAG_OPERR | FLASH_FLAG_WRPERR | 
    FLASH_FLAG_PGAERR | FLASH_FLAG_PGPERR|FLASH_FLAG_PGSERR); 
	
	//��������11�������м仺����
	FLASH_EraseSector(FLASH_Sector_11, VoltageRange_3);
	
	if(Sector_Addr<ADDR_FLASH_SECTOR_4)p_EndAddr=0x4000;//16K
	else if(Sector_Addr>ADDR_FLASH_SECTOR_4)p_EndAddr=0x20000;//128K��С����
	else p_EndAddr=0x10000;//64K
	
	
	while(p_WriteAddr<p_EndAddr)//����֮ǰ������
	{
		if(WriteAddr!=p_WriteAddr)//�ж��ǲ���Ҫд�������
		{
			FLASH_ProgramWord(ADDR_FLASH_SECTOR_11+p_WriteAddr,*(volatile uint32_t*)(Sector_Addr+p_WriteAddr));
		}
		else
		{
			FLASH_ProgramWord(ADDR_FLASH_SECTOR_11+p_WriteAddr,WriteData);
		}
		p_WriteAddr+=4;
	}
	LED1=0;
	switch(Sector_Addr)//ѡ��Ҫд����������в���
	{
		case ADDR_FLASH_SECTOR_0:FLASH_EraseSector(FLASH_Sector_0, VoltageRange_3);break;
		case ADDR_FLASH_SECTOR_1:FLASH_EraseSector(FLASH_Sector_1, VoltageRange_3);break;
		case ADDR_FLASH_SECTOR_2:FLASH_EraseSector(FLASH_Sector_2, VoltageRange_3);break;
		case ADDR_FLASH_SECTOR_3:FLASH_EraseSector(FLASH_Sector_3, VoltageRange_3);break;
		case ADDR_FLASH_SECTOR_4:FLASH_EraseSector(FLASH_Sector_4, VoltageRange_3);break;
		case ADDR_FLASH_SECTOR_5:FLASH_EraseSector(FLASH_Sector_5, VoltageRange_3);break;
		case ADDR_FLASH_SECTOR_6:FLASH_EraseSector(FLASH_Sector_6, VoltageRange_3);break;
		case ADDR_FLASH_SECTOR_7:FLASH_EraseSector(FLASH_Sector_7, VoltageRange_3);break;
		case ADDR_FLASH_SECTOR_8:FLASH_EraseSector(FLASH_Sector_8, VoltageRange_3);break;
		case ADDR_FLASH_SECTOR_9:FLASH_EraseSector(FLASH_Sector_9, VoltageRange_3);break;
		case ADDR_FLASH_SECTOR_10:FLASH_EraseSector(FLASH_Sector_10, VoltageRange_3);break;
		default:break;
	}
	
	p_WriteAddr=0;
	
	while(p_WriteAddr<p_EndAddr)//����֮ǰ������
	{
		//��������
		FLASH_ProgramWord(Sector_Addr+p_WriteAddr,*(volatile uint32_t*)(ADDR_FLASH_SECTOR_11+p_WriteAddr));
		p_WriteAddr+=4;
	}
	
	//����FLASH
	FLASH_Lock(); 
}



/* 
 *��������:void FLASH_WriteStrUint32Data(uint32_t Sector_Addr,uint32_t WriteAddr,uint32_t *WriteData,uint16_t Len)
 *��������:��Flashд��1��32λ���ݵ�����
 *�������:Sector_Addr-������ʼ��ַ
 *�������:WriteAddr-������ַ�µ�ƫ��
 *�������:*WriteData-Ҫд������ݵ�ַ
 *�������:Len-Ҫд������ݳ���
 *�������:��
 */
void FLASH_WriteStrUint32Data(uint32_t Sector_Addr,uint32_t WriteAddr,uint32_t *WriteData,uint16_t Len)
{
	uint32_t p_WriteAddr=0;
	uint32_t p_EndAddr=0;
	
	uint16_t p_Len=0;
	
	//����FLASH ��ʹ�ܶ�FLASH���ƼĴ����ķ���
	FLASH_Unlock();
	//�������ı�־(�����)
	FLASH_ClearFlag(FLASH_FLAG_EOP | FLASH_FLAG_OPERR | FLASH_FLAG_WRPERR | 
    FLASH_FLAG_PGAERR | FLASH_FLAG_PGPERR|FLASH_FLAG_PGSERR); 
	
	//��������11�������м仺����
	FLASH_EraseSector(FLASH_Sector_11, VoltageRange_3);
	
	if(Sector_Addr<ADDR_FLASH_SECTOR_4)p_EndAddr=0x4000;//16K
	else if(Sector_Addr>ADDR_FLASH_SECTOR_4)p_EndAddr=0x20000;//128K��С����
	else p_EndAddr=0x10000;//64K
	
	
	while(p_WriteAddr<p_EndAddr)//����֮ǰ������
	{
		if((p_WriteAddr>=WriteAddr)&&(p_WriteAddr<(WriteAddr+Len*4)))//�ж��ǲ���Ҫд�������
		{
			FLASH_ProgramWord(ADDR_FLASH_SECTOR_11+p_WriteAddr,WriteData[p_Len]);
			p_Len++;
			
		}
		else
		{
			FLASH_ProgramWord(ADDR_FLASH_SECTOR_11+p_WriteAddr,*(volatile uint32_t*)(Sector_Addr+p_WriteAddr));
		}
		p_WriteAddr+=4;
	}
	LED1=0;
	switch(Sector_Addr)//ѡ��Ҫд����������в���
	{
		case ADDR_FLASH_SECTOR_0:FLASH_EraseSector(FLASH_Sector_0, VoltageRange_3);break;
		case ADDR_FLASH_SECTOR_1:FLASH_EraseSector(FLASH_Sector_1, VoltageRange_3);break;
		case ADDR_FLASH_SECTOR_2:FLASH_EraseSector(FLASH_Sector_2, VoltageRange_3);break;
		case ADDR_FLASH_SECTOR_3:FLASH_EraseSector(FLASH_Sector_3, VoltageRange_3);break;
		case ADDR_FLASH_SECTOR_4:FLASH_EraseSector(FLASH_Sector_4, VoltageRange_3);break;
		case ADDR_FLASH_SECTOR_5:FLASH_EraseSector(FLASH_Sector_5, VoltageRange_3);break;
		case ADDR_FLASH_SECTOR_6:FLASH_EraseSector(FLASH_Sector_6, VoltageRange_3);break;
		case ADDR_FLASH_SECTOR_7:FLASH_EraseSector(FLASH_Sector_7, VoltageRange_3);break;
		case ADDR_FLASH_SECTOR_8:FLASH_EraseSector(FLASH_Sector_8, VoltageRange_3);break;
		case ADDR_FLASH_SECTOR_9:FLASH_EraseSector(FLASH_Sector_9, VoltageRange_3);break;
		case ADDR_FLASH_SECTOR_10:FLASH_EraseSector(FLASH_Sector_10, VoltageRange_3);break;
		default:break;
	}
	
	p_WriteAddr=0;
	
	while(p_WriteAddr<p_EndAddr)//����֮ǰ������
	{
		//��������
		FLASH_ProgramWord(Sector_Addr+p_WriteAddr,*(volatile uint32_t*)(ADDR_FLASH_SECTOR_11+p_WriteAddr));
		p_WriteAddr+=4;
	}
	
	//����FLASH
	FLASH_Lock(); 
}



