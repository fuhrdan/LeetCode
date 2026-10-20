#include <limits.h>

static int check(const int* nums, int n, int k)
{
    int previousMax = INT_MIN;
    int hasPrevious = 0;

    for (int start = 0; start < n; start += k)
    {
        int end = start + k;
        int blockMin = nums[start];
        int blockMax = nums[start];
        int descents = 0;

        for (int i = start; i < end; i++)
        {
            int next = (i + 1 < end) ? nums[i + 1] : nums[start];

            if (nums[i] > next)
            {
                descents++;
            }

            if (nums[i] < blockMin)
            {
                blockMin = nums[i];
            }

            if (nums[i] > blockMax)
            {
                blockMax = nums[i];
            }

            if (descents > 1)
            {
                return 0;
            }
        }

        if (hasPrevious && previousMax > blockMin)
        {
            return 0;
        }

        previousMax = blockMax;
        hasPrevious = 1;
    }

    return 1;
}

int sortableIntegers(int* nums, int numsSize)
{
    int retVal = 0;

    for (int d = 1; (long long)d * d <= numsSize; d++)
    {
        if (numsSize % d != 0)
        {
            continue;
        }

        if (check(nums, numsSize, d))
        {
            retVal += d;
        }

        int other = numsSize / d;

        if (other != d && check(nums, numsSize, other))
        {
            retVal += other;
        }
    }

    return retVal;
}
