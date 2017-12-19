/*
---------------------------------------------------------------------------------------------------

    Given an array of integers, return indices of the two numbers such that they add up to a
    specific target.
    You may assume that each input would have exactly one solution, and you may not use the
    same element twice.

    Given nums = [2, 7, 11, 15], target = 9,
    Because nums[0] + nums[1] = 2 + 7 = 9,
    return [0, 1].
----------------------------------------------------------------------------------------------------
*/
#include<stdio.h>
#include<stdlib.h>
#define N 4

int* TwoSum(int* nums, int numsSize, int target);

int main()
{
    int *p;
    int i;
    int target;
    int nums[N] = {2,7,11,15};
    printf("The source data:[");
    for(i = 0; i < N; i++)
    {
        if(i == N -1)
        {
            printf("%d]\n", nums[i]);
        }
        else
        {
            printf("%d, ", nums[i]);
        }
    }
    printf("Input target:");
    scanf("%d", &target);
    p = TwoSum(nums, N, target);
    printf("The result:[");
    for(i = 0; i < 2; i++)
    {
        if(i == 1)
        {
            printf("%d]\n", p[i]);
        }
        else
        {
            printf("%d, ", p[i]);
        }
    }
    free(p);
    return 0;
}


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* TwoSum(int* nums, int numsSize, int target)
{
    int i, j;
    int *p = (int *)malloc(2 * sizeof(int));
    for (i = 0; i < numsSize - 1; i++)
    {
        for (j = i + 1; j < numsSize; j++)
        {
            if (nums[i] + nums[j] == target)
            {
                p[0] = i;
                p[1] = j;
            }
        }
    }
    return p;
}
