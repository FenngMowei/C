#pragma once
#include "stdio.h"
extern int roll_count;

/**
* @brief  :���������
* @author :fmw
* @date   :
**/
unsigned  int rand0(void);

/**
* @brief  :��������
* @author :fmw
* @date   :
**/
void srand1(unsigned int seed);

void testRand();


static int rollem(int sides);

int roll_n_dice(int dice, int sides);

/**
* @brief  :��ɸ�ӳ���
* @author :fmw
* @date   :
**/
void testDice();