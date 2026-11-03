int minMoves(int* nums, int numsSize)
{
    int maxValue = nums[0];
    int sum = 0;

    for (int i = 0; i < numsSize; i++)
    {
        if (nums[i] > maxValue)
        {
            maxValue = nums[i];
        }

        sum += nums[i];
    }

    return maxValue * numsSize - sum;
}
