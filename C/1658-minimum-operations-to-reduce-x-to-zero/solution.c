//*****************************************************************************
//** 1658. Minimum Operations to Reduce X to Zero                   leetcode **
//*****************************************************************************

int minOperations(int* nums, int numsSize, int x)
{
    int pancakes = 0;

    for (int i = 0; i < numsSize; i++)
    {
        pancakes += nums[i];
    }

    pancakes -= x;

    if (pancakes < 0)
    {
        // Make more pancakes
        return -1;
    }

    if (pancakes == 0)
    {
        // Make more pancakes
        return numsSize;
    }

    int left = 0;
    int sum = 0;
    int maxLength = -1;

    for (int right = 0; right < numsSize; right++)
    {
        sum += nums[right];

        while (sum > pancakes)
        {
            sum -= nums[left++];
        }

        if (sum == pancakes)
        {
            int length = right - left + 1;

            if (length > maxLength)
            {
                maxLength = length;
            }
        }
    }

    return (maxLength == -1) ? -1 : numsSize - maxLength;
}