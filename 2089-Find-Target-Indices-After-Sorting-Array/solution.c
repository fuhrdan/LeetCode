#include <stdlib.h>

int* targetIndices(int* nums, int numsSize, int target, int* returnSize)
{
    int less = 0;
    int equal = 0;

    for (int i = 0; i < numsSize; i++)
    {
        if (nums[i] < target)
        {
            less++;
        }
        else if (nums[i] == target)
        {
            equal++;
        }
    }

    *returnSize = equal;

    if (equal == 0)
    {
        return NULL;
    }

    int* retVal = (int*)malloc(sizeof(int) * equal);

    if (retVal == NULL)
    {
        *returnSize = 0;
        return NULL;
    }

    for (int i = 0; i < equal; i++)
    {
        retVal[i] = less + i;
    }

    return retVal;
}
