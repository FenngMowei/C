#include "struct.h"
#include "file.h"

#define SAVEPATH R"(library.txt)"
struct book{ /* �ṹģ�棺����� book */
	char title[MAXTITL];
	char author[MAXAUTL];
	float value;
}; /* �ṹģ����� */

void createBook()
{
	struct book library; /* �� library ����Ϊһ�� book ���͵ı��� */
	printf("Please enter the book title.\n");
	s_gets(library.title, MAXTITL); /* ����title����*/
	printf("Now enter the author.\n");
	s_gets(library.author, MAXAUTL);
	printf("Now enter the value.\n");
	scanf("%f", &library.value);
	printf("%s by %s: $%.2f\n", library.title,
		library.author, library.value);
	printf("%s: \"%s\" ($%.2f)\n", library.author,
		library.title, library.value);
	printf("Done.\n");
}

#define SLEN 81
void getinfo(namect* pst)
{
	char temp[SLEN];
	printf("Please enter your first name.\n");
	s_gets(temp, SLEN);
	// �����ڴ洢����
	pst->fname = (char*)malloc(strlen(temp) + 1);
	// �����������ѷ�����ڴ�
	strcpy(pst->fname, temp);
	printf("Please enter your last name.\n");
	s_gets(temp, SLEN);
	pst->lname = (char*)malloc(strlen(temp) + 1);
	strcpy(pst->lname, temp);
}

void saveStruct()
{
	book library[4] = { {"�����ռ�", "������", 29.9}, {"�������������ɵ�", "��.Ү��˹��", 9.9},
	{"�Կ���", "����", 99.9}, {"����", "�׹���", 49.0} };
	FILE * pf;
	if ((pf = fopen(SAVEPATH, "wb")) == NULL)
	{
		printf("can't open file : %s", SAVEPATH);
		exit(EXIT_FAILURE);
	}
	fwrite(library, sizeof(book), 4,pf);
	fclose(pf);
}
void readStruct()
{
	book library[4];
	FILE* pf;
	if ((pf = fopen(SAVEPATH, "r")) == NULL)
	{
		printf("can't open file : %s", SAVEPATH);
		exit(EXIT_FAILURE);
	}
	fread(library, sizeof(book), 4, pf);
	fclose(pf);
	for (size_t i = 0; i < 4; i++)
	{
		puts(library[i].title);
	}
}

void saveStructDeeply()
{
	namect library[2]; /*= { {"�����ռ�", "������", 29.9}, {"�������������ɵ�", "��.Ү��˹��", 9.9},
{"�Կ���", "����", 99.9}, {"����", "�׹���", 49.0} };*/

	library[0].fname = new char[10]{ "������" };
	library[0].lname = new char[10]{ "������" };
	library[0].letters = 29;
	
	library[1].fname = new char[20]{ "�������������ɵ�"};
	library[1].lname = new char[20]{ "��.Ү��˹��" };
	library[1].letters = 300;

	FILE* pf;
	if ((pf = fopen(SAVEPATH, "wb")) == NULL)
	{
		printf("can't open file : %s", SAVEPATH);
		exit(EXIT_FAILURE);
	}
	printf(" sizeof(library) = %d \n", sizeof(char *));
	for (int i = 0; i < 2; i++)
	{
		printf(" sizeof(library[%d]) = %d \n",i,  sizeof(library[i]));
	}
	fwrite(library, sizeof(book), 2, pf);
	fclose(pf);
}

void readStructDeeply()
{
}
