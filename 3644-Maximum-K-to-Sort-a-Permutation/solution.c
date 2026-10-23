int sortPermutation(int* nums, int numsSize)
{
    int retVal = -1;

    for (int i = 0; i < numsSize; i++)
    {
        if (nums[i] != i)
        {
            retVal &= nums[i];

            if (retVal == 0)
            {
                return 0;
            }
        }
    }

    return retVal < 0 ? 0 : retVal;
}
