#include "file.h"
#include "string.h"
#define LEN 40
void testFile()
{
    int ch; // ��ȡ�ļ�ʱ������ÿ���ַ��ĵط�
    FILE* fp; // ���ļ�ָ�롱
    unsigned long count = 0;
    char fileName[100]= R"(E:\Code\C\.gitignore)";
    //printf("������Ҫ��ȡ���ļ�����");
    //fgets(fileName, 80, stdin);


    //int len = strlen(fileName);
    //fileName[len - 1] = '\0';

    if ((fp = fopen(fileName, "r")) == NULL)
    {
        printf("Can't open %s\n", fileName);
        exit(EXIT_FAILURE);
    }

    char buffer[100] = { 0 };
    int row = 0;

    while (fgets(buffer, 99, fp) != NULL)
    {
        fputs(buffer,stdout);
        row++;
    }

    while ((ch = getc(fp)) != EOF)
    {
        putc(ch, stdout); // �� putchar(ch); ��ͬ
        count++;
    }


    fclose(fp);
    printf("File %s has %lu characters\n", fileName, row);
}

void testReducto()
{
    FILE* in, * out; // ��������ָ�� FILE ��ָ��
    int ch;
    char name[LEN] = R"(E:\Code\C\.gitignore)";; // ��������ļ���
    int count = 0;

    // ��������
    if ((in = fopen(name, "r")) == NULL)
    {
        fprintf(stderr, "I couldn't open the file \"%s\"\n", name);
        exit(EXIT_FAILURE);
    }

    strcat(name, ".red"); // ���ļ��������.red
    if ((out = fopen(name, "w")) == NULL)
    { 
        // ��дģʽ���ļ�
        fprintf(stderr, "Can't create output file.\n");
        exit(3);
    }

    // ��������
    while ((ch = getc(in)) != EOF)
        if (count++ % 3 == 0)
            putc(ch, out);// ��ӡ3���ַ��еĵ�1���ַ�

    // ��β����
    if (fclose(in) != 0 || fclose(out) != 0)
    {
        fprintf(stderr, "Error in closing files\n");
    }   
}

#define MAX 41
#define FILEPATH  R"(E:\Code\C\test.txt)"
void addAWord()
{
    FILE* fp;
    char words[MAX] = FILEPATH;
    if ((fp = fopen(FILEPATH, "a+")) == NULL)
    {
        fprintf(stdout, "Can't open \"wordy\" file.\n");
        exit(EXIT_FAILURE);
    }
    puts("Enter words to add to the file; press the #");
    puts("key at the beginning of a line to terminate.");
    while ((fscanf(stdin, "%40s", words) == 1) && (words[0] != '#'))
        fprintf(fp, "%s\n", words);
    puts("File contents:");
    rewind(fp); /* ���ص��ļ���ʼ�� */
    while (fscanf(fp, "%s", words) == 1)
        puts(words);
    puts("Done!");
    if (fclose(fp) != 0)
        fprintf(stderr, "Error closing file\n");
}

void readWholeFile()
{
    FILE* p;
    if ((p = fopen(FILEPATH, "r")) == NULL)
    {
        fprintf(stdout, "Can't open \"wordy\" file.\n");
        exit(EXIT_FAILURE);
    }

    int initSize = 10;
    char* buffer = new char[initSize];
    int count = 0;
    char temp;
    while ((temp = getc(p)) != EOF)
    {
        buffer[count++] = temp;
        if (count > initSize - 1)
        {
            initSize *= 2;
            char * pc = new char[initSize];
            memcpy(pc, buffer, initSize);
            delete buffer;
            buffer = pc;
        }
    }
    buffer[count] = '\0';
    puts(buffer);
    printf("=========");

}
#define CNTL_Z '\032' /* DOS�ı��ļ��е��ļ���β��� */
#define SLEN 81
void reverse()
{
    char file[SLEN] = FILEPATH;
    char ch;
    FILE* fp;
    long count, last;
    //puts("Enter the name of the file to be processed:");
    //scanf("%80s", file);
    if ((fp = fopen(file, "rb")) == NULL)
    { /* ֻ��ģʽ */
        printf("reverse can't open %s\n", file);
        exit(EXIT_FAILURE);
    }
    fseek(fp, 0L, SEEK_END); /* ��λ���ļ�ĩβ */
    last = ftell(fp);
    for (count = 1L; count <= last; count++)
    {
        fseek(fp, -count, SEEK_END); /* ���� */
        ch = getc(fp);
        if (ch != CNTL_Z && ch != '\r') /* MS-DOS �ļ� */
            putchar(ch);
    }
    putchar('\n');
    fclose(fp);
}

#define BUFSIZE 4096
#define SLEN 81
void append()
{
    FILE* fa, * fs; // fa ָ��Ŀ���ļ���fs ָ��Դ�ļ�
    int files = 0; // ���ӵ��ļ�����
    char file_app[SLEN]; // Ŀ���ļ���
    char file_src[SLEN]; // Դ�ļ���
    int ch;
    puts("Enter name of destination file:");
    s_gets(file_app, SLEN);
    if ((fa = fopen(file_app, "a+")) == NULL)
    {
        fprintf(stderr, "Can't open %s\n", file_app);
        exit(EXIT_FAILURE);
    }
    if (setvbuf(fa, NULL, _IOFBF, BUFSIZE) != 0)
    {
        fputs("Can't create output buffer\n", stderr);
        exit(EXIT_FAILURE);
    }
    puts("Enter name of first source file (empty line to quit):");
    while (s_gets(file_src, SLEN) && file_src[0] != '\0')
    {
        if (strcmp(file_src, file_app) == 0)
            fputs("Can't append file to itself\n", stderr);
        else if ((fs = fopen(file_src, "r")) == NULL)
            fprintf(stderr, "Can't open %s\n", file_src);
        else
        {
            if (setvbuf(fs, NULL, _IOFBF, BUFSIZE) != 0)
            {
                fputs("Can't create input buffer\n", stderr);
                continue;
            }
            append(fs, fa);
            if (ferror(fs) != 0)
                fprintf(stderr, "Error in reading file %s.\n",file_src);
            if (ferror(fa) != 0)
                fprintf(stderr, "Error in writing file %s.\n",file_app);
            fclose(fs);
            files++;
            printf("File %s appended.\n", file_src);
            puts("Next file (empty line to quit):");
        }
    }
    printf("Done appending.%d files appended.\n", files);
    rewind(fa);
    printf("%s contents:\n", file_app);
    while ((ch = getc(fa)) != EOF)
        putchar(ch);
    puts("Done displaying.");
    fclose(fa);
}

void append(FILE* source, FILE* dest)
{
    size_t bytes;
    static char temp[BUFSIZE]; // ֻ����һ��
    
    while ((bytes = fread(temp, sizeof(char), BUFSIZE, source)) > 0)
        fwrite(temp, sizeof(char), bytes, dest);
}

char* s_gets(char* st, int n)
{
    char* ret_val;
    char* find;
    ret_val = fgets(st, n, stdin);
    if (ret_val)
    {
        find = strchr(st, '\n'); // ���һ��з�, ��������ַ���λ��
        if (find) // �����ַ����NULL��
            *find = '\0'; // �ڴ˴�����һ�����ַ�
        else
            while (getchar() != '\n')
                continue;
    }
    return ret_val;
}

#define ARSIZE 1000
void randbin()
{
    double numbers[ARSIZE];
    double value;
    const char* file = "numbers.dat";
    int i;
    long pos;
    FILE* iofile;
    // ����һ�� double���͵�ֵ
    for (i = 0; i < ARSIZE; i++)
        numbers[i] = 100.0 * i + 1.0 / (i + 1);
    // ���Դ��ļ�
    if ((iofile = fopen(file, "wb")) == NULL)
    {
        fprintf(stderr, "Could not open %s for output.\n", file);
        exit(EXIT_FAILURE);
    }
    // �Զ����Ƹ�ʽ������д���ļ�
    fwrite(numbers, sizeof(double), ARSIZE, iofile);

    fclose(iofile);
    if ((iofile = fopen(file, "rb")) == NULL)
    {
        fprintf(stderr,
            "Could not open %s for random access.\n", file);
        exit(EXIT_FAILURE);
    }
    // ���ļ��ж�ȡѡ��������
    printf("Enter an index in the range 0-%d.\n", ARSIZE - 1);
    while (scanf("%d", &i) == 1 && i >= 0 && i < ARSIZE)
    {
        pos = (long)i * sizeof(double); // ����ƫ����
        fseek(iofile, pos, SEEK_SET); // ��λ���˴�
        fread(&value, sizeof(double), 1, iofile);
        printf("The value there is %f.\n", value);
        printf("Next index (out of range to quit):\n");
    }
    // ���
    fclose(iofile);
    puts("Bye!");
}
