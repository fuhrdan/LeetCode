int rob(int* nums, int numsSize)
{
    int prev2 = 0;
    int prev1 = 0;

    for (int i = 0; i < numsSize; i++)
    {
        int take = prev2 + nums[i];
        int skip = prev1;
        int current = take > skip ? take : skip;

        prev2 = prev1;
        prev1 = current;
    }

    return prev1;
}
