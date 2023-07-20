#ifndef __FLASH_H__
#define __FLASH_H__
#include "stm32f4xx.h"                  // Device header

//Sector_Addr

#define  ADDR_FLASH_SECTOR_0   ((uint32_t)0x08000000)//16k 
#define  ADDR_FLASH_SECTOR_1   ((uint32_t)0x08004000)//16k
#define  ADDR_FLASH_SECTOR_2   ((uint32_t)0x08008000)//16k
#define  ADDR_FLASH_SECTOR_3   ((uint32_t)0x0800C000)//16k
#define  ADDR_FLASH_SECTOR_4   ((uint32_t)0x08010000)//64k
#define  ADDR_FLASH_SECTOR_5   ((uint32_t)0x08020000)//128k 
#define  ADDR_FLASH_SECTOR_6   ((uint32_t)0x08040000)//128k 
#define  ADDR_FLASH_SECTOR_7   ((uint32_t)0x08060000)//128k  
#define  ADDR_FLASH_SECTOR_8   ((uint32_t)0x08080000)//128k   
#define  ADDR_FLASH_SECTOR_9   ((uint32_t)0x080A0000)//128k  
#define  ADDR_FLASH_SECTOR_10   ((uint32_t)0x080C0000)//128k  
#define  ADDR_FLASH_SECTOR_11   ((uint32_t)0x080E0000)//128k  

void FLASH_WriteU32tData(uint32_t Sector_Addr,uint32_t WriteAddr,uint32_t WriteData);
void FLASH_WriteStrUint32Data(uint32_t Sector_Addr,uint32_t WriteAddr,uint32_t *WriteData,uint16_t Len);

#endif

