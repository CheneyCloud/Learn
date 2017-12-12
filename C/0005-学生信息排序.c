/*
---------------------------------------------------------------------------------------------------

    定义学生信息，内容包含学号、姓名和绩点。
    从键盘输入学生的个数，并从键盘输入若干学生信息。
    对学生信息按绩点进行递减排序，输出排序后前10名的姓名和学号，一行一条信息

----------------------------------------------------------------------------------------------------
*/

#include<stdio.h>
#include<stdlib.h>

/*定义结构体用来存储学生信息*/
typedef struct
{
    char id[11];    /*记录10位学号*/
    char name[20];  /*记录学生名字*/
    double performance; /*记录绩点信息*/
}STU;

void Sort(STU *pStu, int stuNumber);
void PrintInfo(STU *pStu, int stuNumber);

int main()
{
    int i;
    int stuNumber = 0;  /*记录学生的个数*/
    STU *pStu;  /*定义存储多个学生信息的数组*/
    printf("请输入学生的个数：");
    scanf("%d", &stuNumber);
    getchar();  /*读走换行符*/
    //pStu = (STU *)malloc(stuNumber * sizeof(STU));
    pStu = (STU *)calloc(stuNumber, sizeof(STU));
    for(i = 0; i < stuNumber; i++)
    {
        printf("请输入第%d个学生的学号：", i + 1);
        gets((pStu + i)->id);
        printf("请输入第%d个学生的姓名：", i + 1) ;
        gets((pStu + i)->name);
        printf("请输入第%d个学生的绩点：", i + 1) ;
        scanf("%lf", &(pStu + i)->performance);
        getchar();  /*读走换行符*/
    }
    printf("学生信息如下：\n");
    PrintInfo(pStu, stuNumber);
    Sort(pStu, stuNumber);
    if(stuNumber >= 10)
    {
        printf("前10名的学生信息如下：\n");
        PrintInfo(pStu, 10);
    }
    else
    {
        printf("学生信息如下：\n");
        PrintInfo(pStu, stuNumber);
    }
    free(pStu);
    return 0;
}

void Sort(STU *pStu, int stuNumber)
{
    int i, j;
    STU temp;
    for(i = 0; i < stuNumber - 1; i++)
    {
        for(j = i + 1; j < stuNumber; j++)
        {
            if((pStu + j)->performance > (pStu + i)->performance)
            {
                temp = *(pStu + j);
                *(pStu + j) = *(pStu + i);
                *(pStu + i) = temp;
            }
        }
    }
    return;
}

void PrintInfo(STU *pStu, int stuNumber)
{
    int i;
    printf("-----------------------------------------\n");
    printf("学号\t\t姓名\t绩点\n");
    for(i = 0; i < stuNumber; i++)
    {
        printf("%10s%10s%7.1f\n", (pStu + i)->id, (pStu + i)->name, (pStu + i)->performance);
    }
    return;
}
