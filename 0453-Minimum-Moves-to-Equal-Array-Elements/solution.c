#include <limits.h>

int minMoves(int* nums, int numsSize)
{
    int minValue = INT_MAX;

    for (int i = 0; i < numsSize; i++)
    {
        if (nums[i] < minValue)
        {
            minValue = nums[i];
        }
    }

    long long moves = 0;

    for (int i = 0; i < numsSize; i++)
    {
        moves += (long long)nums[i] - minValue;
    }

    return (int)moves;
}
