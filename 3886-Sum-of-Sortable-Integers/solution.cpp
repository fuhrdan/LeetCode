class Solution
{
private:
    bool check(const vector<int>& nums, int k)
    {
        int n = static_cast<int>(nums.size());
        bool hasPrevious = false;
        int previousMax = 0;

        for (int start = 0; start < n; start += k)
        {
            int end = start + k;
            int blockMin = nums[start];
            int blockMax = nums[start];
            int descents = 0;

            for (int i = start; i < end; i++)
            {
                int next = (i + 1 < end) ? nums[i + 1] : nums[start];

                if (nums[i] > next)
                {
                    descents++;
                }

                blockMin = min(blockMin, nums[i]);
                blockMax = max(blockMax, nums[i]);

                if (descents > 1)
                {
                    return false;
                }
            }

            if (hasPrevious && previousMax > blockMin)
            {
                return false;
            }

            previousMax = blockMax;
            hasPrevious = true;
        }

        return true;
    }

public:
    int sortableIntegers(vector<int>& nums)
    {
        int n = static_cast<int>(nums.size());
        int retVal = 0;

        for (int d = 1; 1LL * d * d <= n; d++)
        {
            if (n % d != 0)
            {
                continue;
            }

            if (check(nums, d))
            {
                retVal += d;
            }

            int other = n / d;

            if (other != d && check(nums, other))
            {
                retVal += other;
            }
        }

        return retVal;
    }
};
