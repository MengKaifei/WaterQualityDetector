#include "FLASH.h"                  // Device header
#include "LED.h"


/* 
 *函数名称:void FLASH_WriteU32tData(uint32_t Sector_Addr,uint32_t WriteAddr,uint32_t WriteData)
 *函数功能:向Flash写入1个32位数据
 *输入变量:Sector_Addr-扇区起始地址
 *输入变量:WriteAddr-扇区地址下的偏移
 *输入变量:WriteData-要写入的数据
 *输出变量:无
 */
void FLASH_WriteU32tData(uint32_t Sector_Addr,uint32_t WriteAddr,uint32_t WriteData)
{
	uint32_t p_WriteAddr=0;
	uint32_t p_EndAddr=0;
	//解锁FLASH ，使能对FLASH控制寄存器的访问
	FLASH_Unlock();
	//清除挂起的标志(如果有)
	FLASH_ClearFlag(FLASH_FLAG_EOP | FLASH_FLAG_OPERR | FLASH_FLAG_WRPERR | 
    FLASH_FLAG_PGAERR | FLASH_FLAG_PGPERR|FLASH_FLAG_PGSERR); 
	
	//擦除扇区11用来做中间缓存区
	FLASH_EraseSector(FLASH_Sector_11, VoltageRange_3);
	
	if(Sector_Addr<ADDR_FLASH_SECTOR_4)p_EndAddr=0x4000;//16K
	else if(Sector_Addr>ADDR_FLASH_SECTOR_4)p_EndAddr=0x20000;//128K大小区域
	else p_EndAddr=0x10000;//64K
	
	
	while(p_WriteAddr<p_EndAddr)//保存之前的数据
	{
		if(WriteAddr!=p_WriteAddr)//判断是不是要写入的数据
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
	switch(Sector_Addr)//选择要写入的扇区进行擦除
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
	
	while(p_WriteAddr<p_EndAddr)//保存之前的数据
	{
		//读回数据
		FLASH_ProgramWord(Sector_Addr+p_WriteAddr,*(volatile uint32_t*)(ADDR_FLASH_SECTOR_11+p_WriteAddr));
		p_WriteAddr+=4;
	}
	
	//上锁FLASH
	FLASH_Lock(); 
}



/* 
 *函数名称:void FLASH_WriteStrUint32Data(uint32_t Sector_Addr,uint32_t WriteAddr,uint32_t *WriteData,uint16_t Len)
 *函数功能:向Flash写入1个32位数据的数组
 *输入变量:Sector_Addr-扇区起始地址
 *输入变量:WriteAddr-扇区地址下的偏移
 *输入变量:*WriteData-要写入的数据地址
 *输入变量:Len-要写入的数据长度
 *输出变量:无
 */
void FLASH_WriteStrUint32Data(uint32_t Sector_Addr,uint32_t WriteAddr,uint32_t *WriteData,uint16_t Len)
{
	uint32_t p_WriteAddr=0;
	uint32_t p_EndAddr=0;
	
	uint16_t p_Len=0;
	
	//解锁FLASH ，使能对FLASH控制寄存器的访问
	FLASH_Unlock();
	//清除挂起的标志(如果有)
	FLASH_ClearFlag(FLASH_FLAG_EOP | FLASH_FLAG_OPERR | FLASH_FLAG_WRPERR | 
    FLASH_FLAG_PGAERR | FLASH_FLAG_PGPERR|FLASH_FLAG_PGSERR); 
	
	//擦除扇区11用来做中间缓存区
	FLASH_EraseSector(FLASH_Sector_11, VoltageRange_3);
	
	if(Sector_Addr<ADDR_FLASH_SECTOR_4)p_EndAddr=0x4000;//16K
	else if(Sector_Addr>ADDR_FLASH_SECTOR_4)p_EndAddr=0x20000;//128K大小区域
	else p_EndAddr=0x10000;//64K
	
	
	while(p_WriteAddr<p_EndAddr)//保存之前的数据
	{
		if((p_WriteAddr>=WriteAddr)&&(p_WriteAddr<(WriteAddr+Len*4)))//判断是不是要写入的数据
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
	switch(Sector_Addr)//选择要写入的扇区进行擦除
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
	
	while(p_WriteAddr<p_EndAddr)//保存之前的数据
	{
		//读回数据
		FLASH_ProgramWord(Sector_Addr+p_WriteAddr,*(volatile uint32_t*)(ADDR_FLASH_SECTOR_11+p_WriteAddr));
		p_WriteAddr+=4;
	}
	
	//上锁FLASH
	FLASH_Lock(); 
}



