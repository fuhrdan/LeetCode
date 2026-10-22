class Solution
{
private:
    bool check(const vector<int>& nums, int zero, int step)
    {
        int n = static_cast<int>(nums.size());
        for (int i = 1; i < n; i++)
        {
            int previous = (zero + (i - 1) * step + n) % n;
            int current = (zero + i * step + n) % n;
            if (nums[previous] > nums[current]) return false;
        }
        return true;
    }

public:
    int minOperations(vector<int>& nums)
    {
        int n = static_cast<int>(nums.size());
        int zero = 0;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] == 0)
            {
                zero = i;
                break;
            }
        }

        int retVal = INT_MAX;
        if (check(nums, zero, 1))
        {
            retVal = min(retVal, zero);
            retVal = min(retVal, n - zero + 2);
        }
        if (check(nums, zero, -1))
        {
            retVal = min(retVal, zero + 2);
            retVal = min(retVal, n - zero);
        }
        return retVal == INT_MAX ? -1 : retVal;
    }
};
