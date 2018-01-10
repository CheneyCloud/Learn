/*
---------------------------------------------------------------------------------------------------

    实现三个基本的排序算法：交换排序，选择交换排序，冒泡排序

----------------------------------------------------------------------------------------------------
*/
#include<stdio.h>
#define N 10

void PrintArray(int *array, int length);
void SwapSort(int *array, int length);
void SelectionSort(int *array, int length);
void BubbleSort(int *array, int length);
void Swap(int *x, int *y);

int main()
{
    int array[N] = {8,2,6,5,1,0,7,9,4,3};
    //SwapSort(array, N);
    //SelectionSort(array, N);
    BubbleSort(array, N);
    PrintArray(array, N);
    return 0;
}

void PrintArray(int *array, int length)
{
    int *p;
    for(p = array; p < array + length; p++)
    {
        printf("%-2d", *p);
    }
    putchar('\n');
    return;
}

void SwapSort(int *array, int length)
{
    int i, j, temp;
    for (i = 0; i < length - 1; i++)
    {
        for (j = i + 1; j < length; j++)
        {
            if (array[j] < array[i])
            {
                Swap(array + j, array + i);
            }
        }
    }
    return;
}

void SelectionSort(int *array, int length)
{
    int i, j, k, temp;
    for (i = 0; i < length - 1; i++)
    {
        k = i;
        for (j = i + 1; j < length; j++)
        {
            if (array[j] < array[k])
            {
                k = j;
            }
        }
        if (k != i)
        {
            Swap(array + k, array + i);
        }
    }
    return;
}

void BubbleSort(int *array, int length)
{
    int i, j, temp;
    for (i = 0; i < length - 1; i++)
    {
        for (j = 0; j < length -1 - i; j++)
        {
            if (array[j] > array[j + 1])
            {
                Swap(array + j, array + j + 1);
            }
        }
    }
    return;
}

void Swap(int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
    return;
}
