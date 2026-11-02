#include <stdlib.h>

static int compareInt(const void* a, const void* b)
{
    int x = *(const int*)a;
    int y = *(const int*)b;

    if (x < y) return -1;
    if (x > y) return 1;
    return 0;
}

int minMoves2(int* nums, int numsSize)
{
    qsort(nums, numsSize, sizeof(int), compareInt);

    int median = nums[numsSize / 2];
    long long moves = 0;

    for (int i = 0; i < numsSize; i++)
    {
        long long diff = (long long)nums[i] - median;

        if (diff < 0)
        {
            diff = -diff;
        }

        moves += diff;
    }

    return (int)moves;
}
