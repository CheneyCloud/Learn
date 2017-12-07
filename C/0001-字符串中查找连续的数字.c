/*
---------------------------------------------------------------------------------------------------

    由用户输入一个字符串，判断该字符串中连续出现的数字，将单独的连续的数字存入一个整形数组中。
    并统计出字符串中连续数字的个数。
    如：
    输入： abc1def23456asd789
    则一共有3个数字，整形数组中存放{1,23456,789}

----------------------------------------------------------------------------------------------------
*/

#include<stdio.h>
#include<ctype.h>

int SearchDigit(char *str, int *numberArray);
int main()
{
    char str[81];
    int numberArray[81];
    int amount = 0;
    printf("请输入一个字符串：");
    gets(str);
    printf("原字符串是：");
    puts(str);
    amount = SearchDigit(str, numberArray);
    printf("字符串中的连续数字有%d个!\n", amount);
    printf("字符串中的连续数字分别是：\n");
    for(int i = 0; i < amount; i++)
    {
        printf("%d\n", numberArray[i]);
    }
    return 0;
}


int SearchDigit(char *str, int *numberArray)
{
    int i = 0;
    int counter = 0;
    int number = 0;
    while(str[i])
    {
        if(isdigit(str[i]))
        {
            number = number * 10 + str[i] - '0';
        }
        if(isdigit(str[i]) && !isdigit(str[i + 1]))
        {
            counter++;
            *numberArray++ = number;
            number = 0;
        }
        i++;
    }
    return counter;
}
