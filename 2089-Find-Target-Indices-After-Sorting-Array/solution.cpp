class Solution
{
public:
    vector<int> targetIndices(vector<int>& nums, int target)
    {
        int less = 0;
        int equal = 0;

        for (int value : nums)
        {
            if (value < target)
            {
                less++;
            }
            else if (value == target)
            {
                equal++;
            }
        }

        vector<int> retVal;
        retVal.reserve(equal);

        for (int i = 0; i < equal; i++)
        {
            retVal.push_back(less + i);
        }

        return retVal;
    }
};
