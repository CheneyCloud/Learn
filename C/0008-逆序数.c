/*
---------------------------------------------------------------------------------------------------

    由键盘输入一个整数，输出它的逆序数

----------------------------------------------------------------------------------------------------
*/

#include<stdio.h>
#include<stdlib.h>

int Reverse(int num);

int main()
{
    int num = 0;
    int reverseNum = 0;
    int flag;
    printf("请输入一个整数：");
    flag = scanf("%d", &num);
    if(!flag)
    {
        printf("输入错误！\n");
        exit(0);
    }
    reverseNum = Reverse(num);
    printf("逆序后的数是：%d\n", reverseNum);
    return 0;
}

int Reverse(int num)
{
    int sign = 1;
    if(num < 0)
    {
        sign = -1;
        num *= -1;
    }
    int reverseNum = 0;
    while (num)
    {
        reverseNum = reverseNum * 10 + num % 10;
        num /= 10;
    }
    return reverseNum * sign;
}

