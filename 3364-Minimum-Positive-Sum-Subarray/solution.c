#include <limits.h>

int minimumSumSubarray(
    int* nums,
    int numsSize,
    int l,
    int r)
{
    int answer = INT_MAX;

    for (int length = l; length <= r; length++)
    {
        int sum = 0;

        for (int i = 0; i < length; i++)
        {
            sum += nums[i];
        }

        if (sum > 0 && sum < answer)
        {
            answer = sum;
        }

        for (int right = length; right < numsSize; right++)
        {
            sum += nums[right];
            sum -= nums[right - length];

            if (sum > 0 && sum < answer)
            {
                answer = sum;
            }
        }
    }

    return answer == INT_MAX ? -1 : answer;
}
