class Solution
{
public:
    int minMoves2(vector<int>& nums)
    {
        sort(nums.begin(), nums.end());

        int median = nums[nums.size() / 2];
        long long moves = 0;

        for (int value : nums)
        {
            long long diff =
                static_cast<long long>(value) - median;

            if (diff < 0)
            {
                diff = -diff;
            }

            moves += diff;
        }

        return static_cast<int>(moves);
    }
};
