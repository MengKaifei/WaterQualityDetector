/*
 * key.h
 *
 * created: 2023-07-05
 *  author: 
 */

#ifndef _KEY_H
#define _KEY_H

#include "ls1b.h"
#include "ls1b_gpio.h"
#include "mips.h"
#include "tick.h"

#ifdef __cplusplus
extern "C" {
#endif

#define KEY_1   43
#define KEY_2   42
#define KEY_3   48
#define KEY_4   49

#define ON      1
#define OFF     0

extern int keyValue;

void key_Init(void);    // 板载按键初始化
int key_Scan(void);     // 板载按键触发判断函数

#ifdef __cplusplus
}
#endif

#endif // _KEY_H

