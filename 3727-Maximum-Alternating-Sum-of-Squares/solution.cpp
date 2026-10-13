class Solution
{
public:
    long long maxAlternatingSum(vector<int>& nums)
    {
        vector<long long> squares;
        squares.reserve(nums.size());

        for (int value : nums)
        {
            long long current = value;
            squares.push_back(current * current);
        }

        sort(squares.begin(), squares.end());

        int negativeCount = static_cast<int>(squares.size()) / 2;
        long long retVal = 0;

        for (int i = 0; i < static_cast<int>(squares.size()); i++)
        {
            if (i < negativeCount)
            {
                retVal -= squares[i];
            }
            else
            {
                retVal += squares[i];
            }
        }

        return retVal;
    }
};
