/*
---------------------------------------------------------------------------------------------------

    实现二分法查找算法:普通版本和指针版本

----------------------------------------------------------------------------------------------------
*/

#include<stdio.h>
#define N 10


int BinarySearch(int array[], int length, int searchNumber);
int BinarySearchPointer(int *array, int length, int searchNumber);

int main()
{
    int array[N] = {0,1,2,3,4,5,6,7,8,9};
    int index = 0;
    int searchNumber = 6;
    index = BinarySearch(array, N, searchNumber);
    printf("%d\n", index);
    index = BinarySearchPointer(array, N, searchNumber);
    printf("%d\n", index);
    return 0;
}

int BinarySearch(int *array, int length, int searchNumber)
{
    int low = 0;
    int high = length - 1;
    int mid = 0;
    while (low <= high)
    {
        mid = low + (high - low) / 2;
        if (searchNumber > array[mid])
        {
            low = mid + 1;
        }
        else if (searchNumber < array[mid])
        {
            high = mid - 1;
        }
        else
        {
            return mid;
        }
    }
    return -1;
}


int BinarySearchPointer(int *array, int length, int searchNumber)
{
    int *low = array;
    int *high = array + length;
    int *mid = NULL;
    while (low <= high)
    {
        mid = low + (high - low) / 2;
        if (searchNumber > *mid)
        {
            low = mid + 1;
        }
        else if (searchNumber < *mid)
        {
            high = mid - 1;
        }
        else
        {
            return mid - array;
        }
    }
    return -1;
}

