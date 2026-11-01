class Solution
{
public:
    int minMoves(vector<int>& nums)
    {
        int minValue = *min_element(nums.begin(), nums.end());
        long long moves = 0;

        for (int value : nums)
        {
            moves += static_cast<long long>(value) - minValue;
        }

        return static_cast<int>(moves);
    }
};
