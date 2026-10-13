#include <stdlib.h>

static int compareLongLong(const void* a, const void* b)
{
    long long left = *(const long long*)a;
    long long right = *(const long long*)b;

    if (left < right)
    {
        return -1;
    }

    if (left > right)
    {
        return 1;
    }

    return 0;
}

long long maxAlternatingSum(int* nums, int numsSize)
{
    long long* squares = (long long*)malloc(sizeof(long long) * numsSize);

    if (squares == NULL)
    {
        return 0;
    }

    for (int i = 0; i < numsSize; i++)
    {
        long long value = nums[i];
        squares[i] = value * value;
    }

    qsort(squares, numsSize, sizeof(long long), compareLongLong);

    int negativeCount = numsSize / 2;
    long long retVal = 0;

    for (int i = 0; i < numsSize; i++)
    {
        if (i < negativeCount)
        {
            retVal -= squares[i];
        }
        else
        {
            retVal += squares[i];
        }
    }

    free(squares);

    return retVal;
}
