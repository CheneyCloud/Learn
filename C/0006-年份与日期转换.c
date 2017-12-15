/*
---------------------------------------------------------------------------------------------------

    功能：用户输入年份和年天数两个参数后，系统输出几几年几月几号
    DATE *CalDate(DATE *date, int yearDays) : 传入DATE类型的指针变量，
    并把年天数传入，用来计算天数和月份

----------------------------------------------------------------------------------------------------
*/

#include<stdio.h>
#define AVERAGE 1   /*记录年份状态是平年，值为1*/
#define LEAP 0   /*记录年份状态是润年，值为0*/

typedef struct
{
    int year;
    int month;
    int day;
    int state;
}DATE;

DATE *CalDate(DATE *date, int yearDays);

int main()
{
    DATE date;
    int yearDays;   /*记录用户输入的年天数*/
    printf("请输入年份：");
    scanf("%d", &date.year);
    printf("请输入年天数：");
    scanf("%d", &yearDays);
    CalDate(&date, yearDays);
    printf("%d年是%s，%d年的第%d天是：%d月%d日\n", date.year,
           date.state ? "平年" : "闰年", date.year, yearDays, date.month, date.day);
    return 0;
}

DATE *CalDate(DATE *date, int yearDays)
{
    int sum = 0;    /*记录每月的累加和，初值为0*/
    int i = 0;  /*记录遍历days数组的下标，从0开始, 其中i+1代表具体的月份*/
    int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    /*判断年份是闰年还是平年，闰年则2月份天数+1*/
    if (date->year % 4 == 0 && date->year % 100 != 0 || date->year % 400 == 0)
    {
        date->state = LEAP;
        days[1]++;
    }
    else
    {
        date->state = AVERAGE;
    }
    if (yearDays <= days[0])    /*如果天数小于31天*/
    {
        date->month = 1;
        date->day = yearDays;
    }
    else
    {
        while (sum + days[i] < yearDays)    /*判断累计天数+当前月份的天数是否小于指定的年天数*/
        {
            sum += days[i++];   /*累计天数，从每月的天数累加*/
        }
        date->month = i + 1;  /*i + 1代表月份*/
        date->day = yearDays - sum;
    }
    return date;
}

