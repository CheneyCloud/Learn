/*
----------------------------------------------------------------------------------------------------
    华氏度转换为摄氏度
    摄氏度转换为华氏度
    步长为20
    打印华氏温度与摄氏温度对照表
----------------------------------------------------------------------------------------------------
*/

#include<stdio.h>

void CelsToFarh();
void FarhToCels();
int main()
{
    CelsToFarh();
    printf("----------------------------\n");
    FarhToCels();
    return 0;
}

void CelsToFarh()
{
    float centigrade, fahrenheit;
    int upper, lower, step;
    lower = 0;  /*设置温度表的最低温度为0*/
    upper = 300;    /*设置温度表的最高温度为300*/
    step = 20;  /*设置步长为20*/
    fahrenheit = lower; /*初始化华氏度的温度*/
    printf("Fahrenheit  To  Centigrade\n");
    printf("----------------------------\n");
    while(fahrenheit <= upper)
    {
        centigrade = (fahrenheit - 32) * 5 / 9;
        printf("%3.0f\t\t%5.1f\n", fahrenheit, centigrade);
        fahrenheit += step;
    }
    return;
}

void FarhToCels()
{
    float centigrade, fahrenheit;
    int upper, lower, step;
    lower = 0;  /*设置温度表的最低温度为0*/
    upper = 300;    /*设置温度表的最高温度为300*/
    step = 20;  /*设置步长为20*/
    centigrade = lower; /*初始化华氏度的温度*/
    printf("Centigrade  To  Fahrenheit\n");
    printf("----------------------------\n");
    while(centigrade <= upper)
    {
        fahrenheit = centigrade * 9 / 5 + 32;
        printf("%3.0f\t\t%5.1f\n", centigrade, fahrenheit);
        centigrade += step;
    }
    return;
}
