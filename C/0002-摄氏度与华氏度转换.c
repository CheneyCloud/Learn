/*
---------------------------------------------------------------------------------------------------
    华氏度转换为摄氏度
    摄氏度转换为华氏度
    步长为20
    打印华氏温度与摄氏温度对照表
----------------------------------------------------------------------------------------------------
*/

#include<stdio.h>
#define LOWER 0     /*设置温度表的最低温度为0*/
#define UPPER 300   /*设置温度表的最高温度为300*/
#define STEP 20     /*设置步长为20*/

void CelsToFarh();
void FarhToCels();
int main()
{
    CelsToFarh();
    printf("----------------------------\n");
    FarhToCels();
    return 0;
}

void FarhToCels()
{
    float centigrade, fahrenheit;
    fahrenheit = LOWER; /*初始化华氏度的温度*/
    printf("Fahrenheit  To  Centigrade\n");
    printf("----------------------------\n");
    while(fahrenheit <= UPPER)
    {
        centigrade = (fahrenheit - 32) * 5 / 9;
        printf("%3.0f\t\t%5.1f\n", fahrenheit, centigrade);
        fahrenheit += STEP;
    }
    return;
}

void CelsToFarh()
{
    float centigrade;
    printf("Centigrade  To  Fahrenheit\n");
    printf("----------------------------\n");
    for(centigrade = LOWER; centigrade <= UPPER; centigrade += STEP)
    {
        printf("%3.0f\t\t%5.1f\n", centigrade, centigrade * 9 / 5 + 32);
    }
    return;
}

