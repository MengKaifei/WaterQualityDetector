/*
 * task.h
 *
 * created: 2023-07-09
 *  author: 
 */

#ifndef _TASK_H
#define _TASK_H

#include "ls1b.h"
#include "ls1b_gpio.h"
#include "mips.h"
#include "tick.h"
#include "key.h"
#include "samotor.h"
#include "dcmotor.h"
#include "uart.h"
#include "pump.h"
#include "rtthread.h"

#ifdef __cplusplus
extern "C" {
#endif

void Task_Start_1(void);    // 任务一全自动运行函数

#ifdef __cplusplus
}
#endif

#endif // _TASK_H

