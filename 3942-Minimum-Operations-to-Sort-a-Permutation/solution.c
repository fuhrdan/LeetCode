#include <limits.h>

static int checkDirection(const int* nums, int numsSize, int zero, int step)
{
    for (int i = 1; i < numsSize; i++)
    {
        int previous = (zero + (i - 1) * step) % numsSize;
        int current = (zero + i * step) % numsSize;

        if (previous < 0) previous += numsSize;
        if (current < 0) current += numsSize;

        if (nums[previous] > nums[current]) return 0;
    }
    return 1;
}

int minOperations(int* nums, int numsSize)
{
    int zero = 0;
    for (int i = 0; i < numsSize; i++)
    {
        if (nums[i] == 0)
        {
            zero = i;
            break;
        }
    }

    int retVal = INT_MAX;

    if (checkDirection(nums, numsSize, zero, 1))
    {
        if (zero < retVal) retVal = zero;
        int candidate = numsSize - zero + 2;
        if (candidate < retVal) retVal = candidate;
    }

    if (checkDirection(nums, numsSize, zero, -1))
    {
        int candidate = zero + 2;
        if (candidate < retVal) retVal = candidate;
        candidate = numsSize - zero;
        if (candidate < retVal) retVal = candidate;
    }

    return retVal == INT_MAX ? -1 : retVal;
}
