class Solution
{
public:
    int minimumSumSubarray(
        vector<int>& nums,
        int l,
        int r)
    {
        int answer = INT_MAX;
        int n = static_cast<int>(nums.size());

        for (int length = l; length <= r; length++)
        {
            int sum = 0;

            for (int i = 0; i < length; i++)
            {
                sum += nums[i];
            }

            if (sum > 0)
            {
                answer = min(answer, sum);
            }

            for (int right = length; right < n; right++)
            {
                sum += nums[right];
                sum -= nums[right - length];

                if (sum > 0)
                {
                    answer = min(answer, sum);
                }
            }
        }

        return answer == INT_MAX ? -1 : answer;
    }
};
