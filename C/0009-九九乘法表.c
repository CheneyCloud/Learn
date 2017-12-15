/*
---------------------------------------------------------------------------------------------------

    用三种方式打印九九乘法表

----------------------------------------------------------------------------------------------------
*/

#include<stdio.h>

void PrintTableVersion1();
void PrintTableVersion2();
void PrintTableVersion3();

int main()
{
    PrintTableVersion1();
    PrintTableVersion2();
    PrintTableVersion3();
    return 0;
}


void PrintTableVersion1()
{
    int i, j;
    printf("九九乘法表版本1\n");
    for(i = 1; i < 10; i++)
    {
        printf("%d\t", i);
    }
    putchar('\n');
    for(i = 1; i < 10; i++)
    {
        printf("-\t");
    }
    putchar('\n');
    for(i = 1; i < 10; i++)
    {
        for(j = 1; j < 10; j++)
        {
            printf("%d\t", i * j);
        }
        putchar('\n');
    }
    return;
}

void PrintTableVersion2()
{
    int i, j;
    printf("九九乘法表版本2\n");
    for(i = 1; i < 10; i++)
    {
        printf("%d\t", i);
    }
    putchar('\n');
    for(i = 1; i < 10; i++)
    {
        printf("-\t");
    }
    putchar('\n');
    for(i = 1; i < 10; i++)
    {
        for(j = 1; j <= i; j++)
        {
            printf("%d\t", i * j);
        }
        putchar('\n');
    }
    return;
}

void PrintTableVersion3()
{
    int i, j;
    printf("九九乘法表版本3\n");
    for(i = 1; i < 10; i++)
    {
        printf("%d\t", i);
    }
    putchar('\n');
    for(i = 1; i < 10; i++)
    {
        printf("-\t");
    }
    putchar('\n');
    for(i = 1; i < 10; i++)
    {
        for(j = 1; j < i; j++)
        {
            printf(" \t");
        }
        for(j = i; j < 10; j++)
        {
            printf("%d\t", i * j);
        }
        putchar('\n');
    }
    return;
}
