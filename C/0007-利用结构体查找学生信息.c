/*
---------------------------------------------------------------------------------------------------

    有N名（不固定）学生的数据，请编写函数,函数返回指定学号的学生数据。
    若没有找到指定学号，则将a指向的数组中下标为0的元素学号置为空串，成绩置为-1，并作为函数值返回

----------------------------------------------------------------------------------------------------
*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct
{
    char num[11];
    float score;
}STU;

STU *InitalStuData(int stuNumber);
STU SearchStudsNum(STU *stu, char *searchNum, int stuNumber);

int main()
{
    int stuNumber = 0;
    char searchNumber[11];
    STU *stu, searchStu;
    printf("请输入学生的数量：");
    scanf("%d", &stuNumber);
    getchar();
    stu = InitalStuData(stuNumber); /*动态申请的内存空间，必须释放内存空间*/
    printf("请输入需要查找的学号：");
    gets(searchNumber);
    searchStu = SearchStudsNum(stu, searchNumber, stuNumber);
    printf("查找到的学生数据如下：\n");
    printf("学号\t\t成绩\n");
    printf("%s\t%.1f", stu->num, stu->score);
    free(stu);
    return 0;
}

STU *InitalStuData(int stuNumber)
{
    int i;
    STU *stu = (STU *)calloc(stuNumber, sizeof(STU));
    for (i = 0; i < stuNumber; i++)
    {
        printf("请输入第%d个学生的学号：", i + 1);
        gets(stu->num);
        printf("请输入第%d个学生的成绩：", i + 1);
        scanf("%f", &stu->score);
        getchar();
    }
    printf("学生数据初始化完毕！\n");
    printf("-----------------------------------------\n");
    return stu;
}

STU SearchStudsNum(STU *stu, char *searchNum, int stuNumber)
{
    int i;
    for(i = 0; i < stuNumber; i++)
    {
        if(strcmp((stu + i)->num, searchNum) == 0)
        {
            return *(stu + i);
        }
    }
    if(i == stuNumber)
    {
        strcpy(stu->num, "");
        stu->score = -1;
    }
    return *stu;
}
