//*****************************************************************************
//** 3524. Find X Value of Array I                                  leetcode **
//*****************************************************************************

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
long long* resultArray(int* nums, int numsSize, int k, int* returnSize)
{
    long long* retVal = calloc(k, sizeof(long long));

    *returnSize = k;

    if (retVal == NULL)
    {
        *returnSize = 0;
        return NULL;
    }

    long long dp[5] = {0};
    long long next[5];

    for (int i = 0; i < numsSize; i++)
    {
        int value = nums[i] % k;

        for (int r = 0; r < k; r++)
        {
            next[r] = 0;
        }

        next[value]++;

        for (int r = 0; r < k; r++)
        {
            int newRemainder = (r * value) % k;

            next[newRemainder] += dp[r];
        }

        for (int r = 0; r < k; r++)
        {
            dp[r] = next[r];
            retVal[r] += dp[r];
        }
    }

    return retVal;
}