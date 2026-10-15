class Solution
{
public:
    int sumCounts(vector<int>& nums)
    {
        int retVal = 0;

        for (int start = 0; start < static_cast<int>(nums.size()); start++)
        {
            bool seen[101] = {false};
            int distinct = 0;

            for (int end = start; end < static_cast<int>(nums.size()); end++)
            {
                int value = nums[end];

                if (!seen[value])
                {
                    seen[value] = true;
                    distinct++;
                }

                retVal += distinct * distinct;
            }
        }

        return retVal;
    }
};
