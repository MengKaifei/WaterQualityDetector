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

#define LIMIT_KEY_1     57  // ����λ��������
#define LIMIT_KEY_2     56  // ����λ��������

#define ON      1
#define OFF     0

void Limit_Init(void);  // ��λ���س�ʼ��
int Limit_Scan(void);   // ��λ���ش����ж�

#ifdef __cplusplus
}
#endif

#endif // _LIMIT_H

