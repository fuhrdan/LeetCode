//*****************************************************************************
//** 3904. Smallest Stable Index II                                 leetcode **
//*****************************************************************************

int firstStableIndex(int* nums, int numsSize, int k)
{
    int* suffixMin;
    int prefixMax;
    int i;
    int retVal = -1;

    suffixMin = (int*)malloc(numsSize * sizeof(int));

    if (suffixMin == NULL)
    {
        return -1;
    }

    suffixMin[numsSize - 1] = nums[numsSize - 1];

    for (i = numsSize - 2; i >= 0; i--)
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

    for (i = 0; i < numsSize; i++)
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