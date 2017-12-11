/*
---------------------------------------------------------------------------------------------------

    1.打印输入中单词长度的直方图，水平方向和垂直方向
    2.打印输入中各个字符出现频度的直方图

----------------------------------------------------------------------------------------------------
*/

#include<stdio.h>
#include<string.h>
#define IN 1    /*记录状态，判断在单词内*/
#define OUT 0   /*记录状态，判断在单词外*/
void PrintHorizontalHistogram();
void PrintVerticalHistogram();

int main()
{
    PrintHorizontalHistogram();
    //PrintVerticalHistogram();
    return 0;
}

void PrintHorizontalHistogram()
{
    int c, nv, nvl, state, i, j;
    char str[100][20];
    char temp[20];
    int vocabLenth[100];
    i  = 0;
    j = 0;
    int *pv = vocabLenth;
    nvl = 0; /*记录单词的长度*/
    nv = 0;
    state = OUT; /*记录单词的状态*/
    while ((c = getchar()) != EOF)
    {
        if (c == ' ' || c == '\t' || c == '\n')
        {
            if (state == IN)
            {
                str[j++][i] = 0;
                i = 0;
                *pv++ = nvl;
            }
            nvl = 0;
            state = OUT;
        }
        else if (state == OUT)
        {
            str[j][i++] = c;
            state = IN;
            nvl++;
            nv++;
        }
        else if (state == IN)
        {
            str[j][i++] = c;
            nvl++;
        }
    }
    printf("水平直方图如下：\n");
    for(i = 0; i < nv; i++)
    {
        printf("%s:", str[i]);
        for(j = 0; j < vocabLenth[i]; j++)
        {
            printf(" * ");
        }
        putchar('\n');
    }
    return;
}
