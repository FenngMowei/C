#pragma once
#include <stdio.h>
#include <stdlib.h> // �ṩ exit()��ԭ��

/**
* @brief  :���� File* fopen putc getc ����
* @author :fmw
* @date   :
**/
void testFile();
/**
* @brief  :���Ը��ƿ����ļ�
* @author :fmw
* @date   :
**/
void testReducto();

/**
* @brief  :fprintf fscanf rewind �÷�
* @author :fmw
* @date   :
**/
void addAWord();
/**
* @brief  :ʹ���Զ�����ʵ�ֶ�ȡ�����ļ�
* @author :fmw
* @date   :
**/
void readWholeFile();

/**
* @brief  :������ʾ�ļ����ݣ� fseek �� ftell ���÷�
* @author :fmw
* @date   :
**/
void reverse();


void append();

/**
* @brief  :END
* @author :fmw
* @date   :
**/
void append(FILE* source, FILE* dest);


/**
* @brief  :�ӿ���̨���벻�� \n ���ַ���
* @author :fmw
* @date   :
**/
char* s_gets(char* st, int n);

/**
* @brief  :����һ�� double���飬�Զ����Ƹ�ʽд�뵽�ļ��У���ʹ��������ʺ���������������
* @author :fmw
* @date   :
**/
void  randbin();