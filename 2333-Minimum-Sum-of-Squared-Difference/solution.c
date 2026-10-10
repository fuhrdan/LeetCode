#include <stdlib.h>

long long minSumSquareDiff(int* nums1, int nums1Size, int* nums2, int nums2Size, int k1, int k2)
{
    (void)nums2Size;

    const int MAX_DIFF = 100000;
    long long* count = (long long*)calloc(MAX_DIFF + 1, sizeof(long long));

    if (count == NULL)
    {
        return 0;
    }

    long long totalDiff = 0;
    int maxDiff = 0;

    for (int i = 0; i < nums1Size; i++)
    {
        int diff = nums1[i] - nums2[i];

        if (diff < 0)
        {
            diff = -diff;
        }

        count[diff]++;
        totalDiff += diff;

        if (diff > maxDiff)
        {
            maxDiff = diff;
        }
    }

    long long operations = (long long)k1 + (long long)k2;

    if (operations >= totalDiff)
    {
        free(count);
        return 0;
    }

    for (int diff = maxDiff; diff > 0 && operations > 0; diff--)
    {
        if (count[diff] == 0)
        {
            continue;
        }

        long long moved = count[diff] < operations ? count[diff] : operations;

        count[diff] -= moved;
        count[diff - 1] += moved;
        operations -= moved;
    }

    long long retVal = 0;

    for (int diff = 1; diff <= maxDiff; diff++)
    {
        retVal += count[diff] * (long long)diff * (long long)diff;
    }

    free(count);

    return retVal;
}
