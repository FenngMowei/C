#pragma once
#include "stdio.h"
#include "string.h"
#define PAGES 336
#define WORDS 65618
/*
*  brief : ����һ������
*  num : ���ε�ĸ���
*/
void printDiamond(int num);

/*
*  brief : ����һ������, �����ǿյ�
*  num : ���ε�ĸ���
*/
void printDiamondCentralBlank(int num);

/*
*  brief : printf �÷�����
*/
void testPrintf();


/*
*  brief : scanf �÷�����
*/
void testScanf();

/**
* @brief  :
* @author :
* @date   :2023-3-21 14:52:04
**/
void testGetPuts();


#include "rand.h"
void testExtent();