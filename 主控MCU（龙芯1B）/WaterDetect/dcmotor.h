/*
 * dcmotor.h
 *
 * created: 2023-07-06
 *  author: 
 */

#ifndef _DCMOTOR_H
#define _DCMOTOR_H

#include "ls1b.h"
#include "ls1b_gpio.h"
#include "mips.h"
#include "tick.h"

#ifdef __cplusplus
extern "C" {
#endif

// 电机IO口定义 
#define DC_X_C2			39
#define DC_X_C1		    38

#define ON  1
#define OFF 0

#define DCMOTOR_STATE_STOP      0
#define DCMOTOR_STATE_POS       1
#define DCMOTOR_STATE_DEV       2

extern int dcmotor_Current_Status;

void dcmotor_Init(void);        // DC电机初始化
void dcmotor_Positive(void);    // DC电机上转
void dcmotor_Reverse(void);     // DC电机下转
void dcmotor_Stop(void);        // DC电机停止

#ifdef __cplusplus
}
#endif

#endif // _DCMOTOR_H

