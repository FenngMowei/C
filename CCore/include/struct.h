#pragma once
#include <stdio.h>
#include <string.h>

#define MAXTITL 41 /* ��������󳤶� + 1 */
#define MAXAUTL 31 /* ������������󳤶� + 1*/


extern struct book;

struct namect {
	char* fname; // ��ָ���������
	char* lname;
	int letters;
};

void createBook();

void getinfo(struct namect* pst);

/**
* @brief  :����ṹ��
* @author :fmw
* @date   :
**/
void saveStruct();

/**
* @brief  :���ļ����Զ��������ķ�ʽ���ļ�
* @author :fmw
* @date   :
**/
void readStruct();

/**
* @brief  :��ʱû�з�������ṹ���ָ������
* @author :fmw
* @date   :
**/
void saveStructDeeply();

void readStructDeeply();