/*
 * pump.h
 *
 * created: 2023-07-08
 *  author: 
 */

#ifndef _PUMP_H
#define _PUMP_H

#include "ls1b.h"
#include "ls1b_gpio.h"
#include "mips.h"
#include "tick.h"

#ifdef __cplusplus
extern "C" {
#endif

#define PUMP_1      24
#define PUMP_2      40
#define PUMP_3      3
#define PUMP_4      2

#define ON  1
#define OFF 0

void pump_Init(void);           // 水泵初始化
void set_Pump_Stop(int mode);   // 设置水泵停止
void set_Pump_Start(int mode);  // 设置水泵运转

#ifdef __cplusplus
}
#endif

#endif // _PUMP_H

