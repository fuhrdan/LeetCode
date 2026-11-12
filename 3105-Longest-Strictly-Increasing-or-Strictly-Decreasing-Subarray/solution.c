int longestMonotonicSubarray(int* nums, int numsSize)
{
    int increasing = 1;
    int decreasing = 1;
    int answer = 1;

    for (int i = 1; i < numsSize; i++)
    {
        if (nums[i] > nums[i - 1])
        {
            increasing++;
            decreasing = 1;
        }
        else if (nums[i] < nums[i - 1])
        {
            decreasing++;
            increasing = 1;
        }
        else
        {
            increasing = 1;
            decreasing = 1;
        }

        if (increasing > answer)
            answer = increasing;

        if (decreasing > answer)
            answer = decreasing;
    }

    return answer;
}
