//*****************************************************************************
//** 3903. Smallest Stable Index I                                  leetcode **
//*****************************************************************************

int firstStableIndex(int* nums, int numsSize, int k)
{
    int* suffixMin = malloc(sizeof(int) * numsSize);
    int prefixMax;
    int retVal = -1;

    suffixMin[numsSize - 1] = nums[numsSize - 1];

    for (int i = numsSize - 2; i >= 0; i--)
    {
        if (nums[i] < suffixMin[i + 1])
        {
            suffixMin[i] = nums[i];
        }
        else
        {
            suffixMin[i] = suffixMin[i + 1];
        }
    }

    prefixMax = nums[0];

    for (int i = 0; i < numsSize; i++)
    {
        if (nums[i] > prefixMax)
        {
            prefixMax = nums[i];
        }

        if (prefixMax - suffixMin[i] <= k)
        {
            retVal = i;
            break;
        }
    }

    free(suffixMin);

    return retVal;
}