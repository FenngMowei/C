#include "char.h"
void testCharTrans()
{
	//�ַ�ת����
	char chs[10] = "433";
	int aNum =  10;
	double aDouble = 0.11;
	aNum = atoi(chs);
	aDouble = atof(chs);
	printf("ת����aNum = %f\n", aDouble);

	//����ת�ַ�
	char dataTC[5] = "sss";
	//sprintf(dataTC, "%d", aNum);
	_itoa(aNum, dataTC, 10);
	printf("int ת char[] %s", dataTC);
}

void getLine(char*  buffer, int len)
{
	int i = 0;
	char character;
	do {
		character = getchar();
		buffer[i++] = character;
		if (i > len - 2)
		{
			break;
		}
	} while (character != '\n');
	buffer[i] = '\0';
}


bool alphabetic(const char c)
{
	if ((c >= 'a' && c <= 'z') || c >= 'A' && c <= 'Z') {
		return true;
	}
	return false;
}

int countWords(const char* String)
{
	int count = 0, index = 0;
	bool flag = true; //�����ж�һ�������Ƿ�����
	while (String[index] != '\0') {
		if (alphabetic(String[index]) || (String[index] == '`' && alphabetic(String[index + 1]))) 
		{
			if (flag) {  //�ж��ҵ���һ������
				count++;
				flag = false; //��֤��������ʶ�ȡ���
			}
		}
		else {
			flag = true;
		}
		index++;
	}
	return count;
}

void concat(char* result, const char* str1, const char* str2)
{
	int i = 0, j = 0; //i Ӧ�����ⲿ����
	for (i = 0; str1[i] != '\0'; ++i) {
		result[i] = str1[i];
	}
	for (j = 0; str2[j] != '\0'; ++j) {
		result[i++] = str2[j];
	}
	result[i] = '\0';
}

int length(const char* String)
{
	int len = 0;
	while (String[len] != '\0') {
		len++;
	}
	return len;
}



void test1()
{
	char buffer[100];
	getLine(buffer, 100);
	int count = countWords(buffer);
	printf("���ʸ��� : %d", count);
}

void test2()
{
	char result[20];
	char str1[10] = "homeg";
	char str2[10] = "work";

	//ƴ��
	//concat(result, str1, str2);
	//puts(result);
	
	//����
	printf("���ʵĸ�����%d", length(str1));


}


