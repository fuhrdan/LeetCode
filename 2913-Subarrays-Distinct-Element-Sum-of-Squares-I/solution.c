int sumCounts(int* nums, int numsSize)
{
    int retVal = 0;

    for (int start = 0; start < numsSize; start++)
    {
        int seen[101] = {0};
        int distinct = 0;

        for (int end = start; end < numsSize; end++)
        {
            int value = nums[end];

            if (seen[value] == 0)
            {
                seen[value] = 1;
                distinct++;
            }

            retVal += distinct * distinct;
        }
    }

    return retVal;
}
