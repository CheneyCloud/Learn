/*
---------------------------------------------------------------------------------------------------

    CountGetChar():统计输入的字符数
    CountLine():统计输入中的行数
    CountWhite():统计空格、制表符与换行符个数
    InToOutSpace():将输入复制到输出，并将其中连续的多个空格用一个空格代替
    InToOutTable():将输入复制到输出，并将其中的制表符替换为\t，把回退符替换为\b，把反斜杠替换为\\。
    CountVocab():统计单词的个数，行数，字符数
    CountVocabAndPrint():统计单词的个数，并以每行一个单词的形式打印其输入。
----------------------------------------------------------------------------------------------------
*/

#include<stdio.h>
#define FIRST 1 /*记录当前状态是否是第一次出现*/
#define NOTFIRST 0  /*记录当前状态不是第一次出现*/
#define IN 1    /*记录状态，判断在单词内*/
#define OUT 0   /*记录状态，判断在单词外*/

void  CountGetChar();
void CountLine();
void CountWhite();
void InToOutSpace();
void InToOutTable();
void CountVocab();
void CountVocabAndPrint();

int main()
{
    printf("---------CountGetChar()函数---------\n");
    CountGetChar();
    printf("\n---------CountLine()函数---------\n");
    CountLine();
    printf("\n---------CountWhite()函数---------\n");
    CountWhite();
    printf("\n---------InToOutSpace()函数---------\n");
    InToOutSpace();
    printf("\n---------InToOutTable()函数---------\n");
    InToOutTable();
    printf("\n---------CountVocab()函数---------\n");
    CountVocab();
    printf("\n---------CountVocabAndPrint()函数---------\n");
    CountVocabAndPrint();
    return 0;
}


/*
当输入的字符遇到文本结束符时，终止输入与打印。在windows中按ctrl + z 后按ENTER等于EOF
在这种统计方法中，注意换行符、制表符等空白符也被统计入字符数。
*/
void CountGetChar()
{
    long nc;
    nc = 0; /*nc用于记录输入的字符数，初值为0*/
    while (getchar() != EOF)
    {
        nc++;
    }
    printf("The count of char are : %ld", nc);
    return;
}

void CountLine()
{
    int c, nl;
    nl = 0; /*nl用于记录换行符的个数*/
    while ((c = getchar()) != EOF)
    {
        if(c == '\n')
        {
            nl++;
        }
    }
    printf("输入文本的行数有：%d", nl);
    return;
}

void CountWhite()
{
    int c, ns, nt, nn, other;
    ns = 0; /*记录空格的个数*/
    nt = 0; /*记录制表符的个数*/
    nn = 0; /*记录换行符的个数*/
    other = 0;  /*记录其他字符的个数*/
    while ((c = getchar()) != EOF)
    {
        if (c == ' ')
        {
            ns++;
        }
        else if (c == '\t')
        {
            nt++;
        }
        else if (c == '\n')
        {
            nn++;
        }
        else
        {
            other++;
        }
    }
    printf("空格数量是：%d\t制表符的数量是：%d\t换行符的数量是：%d", ns, nt, nn);
    return;
}


void InToOutSpace()
{
    int c, state;
    state = FIRST;   /*记录空格的状态，初始为FIRST,FIRST是符号常量,值为1*/
    while ((c = getchar()) != EOF)
    {
        if (c == ' ')
        {
            if(state)
            {
                putchar(c);
            }
            state = NOTFIRST;
        }
        else
        {
            putchar(c);
            state = FIRST;
        }
    }
    return;
}

void InToOutTable()
{
    int c;
    while ((c = getchar()) != EOF)
    {
        if (c == '\t')
        {
            printf("\\t");
        }
        else if (c == '\b')
        {
            printf("\\b");
        }
        else if (c == '\\')
        {
            printf("\\");
        }
        else
        {
            putchar(c);
        }
    }
    return;
}

void CountVocab()
{
    int c, nl, nv, nc, state;
    nl = 0; /*统计行数*/
    nv = 0; /*统计单词数*/
    nc = 0; /*统计字符的个数*/
    state = OUT;
    /*
    记录单词的状态，如果有空白符则置为OUT（0）,
    如果不是空白符的情况下并且状态是OUT，则判断出是单词的第一个字母，
    此时将state置为IN，表示是一个单词，单词数自增。
    */
    while ((c = getchar()) != EOF)
    {
        nc++;
        if (c == '\n')
        {
            nl++;
        }
        if (c == ' '|| c == '\t' || c == '\n')
        {
            state = OUT;
        }
        else if (state == OUT)
        {
            state = IN;
            nv++;
        }
    }
    printf("行数为：%d\t单词数为：%d\t字符数为：%d\n", nl, nv, nc);
    return;
}

void CountVocabAndPrint()
{
    int c, nv, state;
    nv = 0; /*记录单词的个数*/
    state = OUT; /*记录单词的状态*/
    while ((c = getchar()) != EOF)
    {
        if (c == ' '|| c == '\t' || c == '\n')
        {
            if(state = IN)
            {
                putchar('\n');
            }
            state = OUT;
        }
        else if (state == OUT)
        {
            state = IN;
            nv++;
            putchar(c);
        }
        else if (state == IN)
        {
            putchar(c);
        }
    }
    return;
}
