class Solution
{
public:
    int minMoves(vector<int>& nums)
    {
        int maxValue = *max_element(nums.begin(), nums.end());
        int sum = 0;

        for (int value : nums)
        {
            sum += value;
        }

        return maxValue * static_cast<int>(nums.size()) - sum;
    }
};
