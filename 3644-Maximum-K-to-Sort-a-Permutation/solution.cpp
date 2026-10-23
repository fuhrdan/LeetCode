class Solution
{
public:
    int sortPermutation(vector<int>& nums)
    {
        int retVal = -1;

        for (int i = 0; i < static_cast<int>(nums.size()); i++)
        {
            if (nums[i] != i)
            {
                retVal &= nums[i];

                if (retVal == 0)
                {
                    return 0;
                }
            }
        }

        return max(retVal, 0);
    }
};
