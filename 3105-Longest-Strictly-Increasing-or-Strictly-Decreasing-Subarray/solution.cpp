class Solution
{
public:
    int longestMonotonicSubarray(vector<int>& nums)
    {
        int increasing = 1;
        int decreasing = 1;
        int answer = 1;

        for (int i = 1; i < static_cast<int>(nums.size()); i++)
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

            answer = max(answer, max(increasing, decreasing));
        }

        return answer;
    }
};
