/*
 * limit.h
 *
 * created: 2023-07-09
 *  author: 
 */

#ifndef _LIMIT_H
#define _LIMIT_H

#include "ls1b.h"
#include "ls1b_gpio.h"
#include "mips.h"
#include "tick.h"

#ifdef __cplusplus
extern "C" {
#endif

#define LIMIT_KEY_1     57  // 下限位开关引脚
#define LIMIT_KEY_2     56  // 上限位开关引脚

#define ON      1
#define OFF     0

void Limit_Init(void);  // 限位开关初始化
int Limit_Scan(void);   // 限位开关触发判断

#ifdef __cplusplus
}
#endif

#endif // _LIMIT_H

