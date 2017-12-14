/*
---------------------------------------------------------------------------------------------------

    PrintYearsDays() : 用户输入年份和年天数两个参数后，系统输出几几年几月几号

----------------------------------------------------------------------------------------------------
*/

#include<stdio.h>
#define AVERAGE 1   /*记录年份状态是平年，值为1*/
#define LEAP 0   /*记录年份状态是润年，值为0*/

void PrintThisYearsDays();

int main()
{
    PrintThisYearsDays();
    return 0;
}

void PrintThisYearsDays()
{
    int day = 0;    /*存储日期中的天数*/
    int month = 0;  /*存储日期中的月份*/
    int year = 0;   /*存储日期中的年份*/
    int yearDays;   /*记录用户输入的年天数*/
    int sum = 0;    /*记录每月的累加和，初值为0*/
    int i = 0;  /*记录遍历days数组的下标，从0开始, 其中i+1代表具体的月份*/
    int state = AVERAGE;    /*将年份状态初值置为平年*/
    int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    printf("请输入年份：");
    scanf("%d", &year);
    /*判断年份是闰年还是平年，闰年则2月份天数+1*/
    if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
    {
        state = LEAP;
        days[1]++;
    }
    printf("请输入年天数：");
    scanf("%d", &yearDays);
    if (yearDays <= days[0])    /*如果天数小于31天*/
    {
        printf("%d年是%s，%d年的第%d天是：%d月%d日\n", year, state ? "平年" : "闰年", year, yearDays, month = 1, day = yearDays);
    }
    else    /*如果天数大于31天*/
    {
        while (sum + days[i] < yearDays)    /*判断累计天数+当前月份的天数是否小于指定的年天数*/
        {
            sum += days[i++];   /*累计天数，从每月的天数累加*/
        }
        month = i + 1;  /*i + 1代表月份*/
        day = yearDays - sum;
        /*当累计天数+当前月份的天数大于指定的年天数时，该月份的天数计算 = 年天数 - 累计天数*/
        printf("%d年是%s，%d年的第%d天是：%d月%d日\n", year, state ? "平年" : "闰年", year, yearDays, month, day);
    }
    return;
}
