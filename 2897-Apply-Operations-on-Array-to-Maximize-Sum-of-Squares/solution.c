#include <stdint.h>

int maxSum(int* nums, int numsSize, int k)
{
    const int MOD = 1000000007;
    const int BITS = 31;
    int bitCount[31] = {0};

    for (int i = 0; i < numsSize; i++)
    {
        for (int bit = 0; bit < BITS; bit++)
        {
            if ((nums[i] >> bit) & 1)
            {
                bitCount[bit]++;
            }
        }
    }

    int64_t retVal = 0;

    for (int i = 0; i < k; i++)
    {
        int64_t value = 0;

        for (int bit = 0; bit < BITS; bit++)
        {
            if (bitCount[bit] > 0)
            {
                value |= 1LL << bit;
                bitCount[bit]--;
            }
        }

        int64_t modValue = value % MOD;
        retVal = (retVal + (modValue * modValue) % MOD) % MOD;
    }

    return (int)retVal;
}
