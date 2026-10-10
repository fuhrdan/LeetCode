class Solution
{
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2)
    {
        const int MAX_DIFF = 100000;
        vector<long long> count(MAX_DIFF + 1, 0);

        long long totalDiff = 0;
        int maxDiff = 0;

        for (int i = 0; i < static_cast<int>(nums1.size()); i++)
        {
            int diff = abs(nums1[i] - nums2[i]);

            count[diff]++;
            totalDiff += diff;
            maxDiff = max(maxDiff, diff);
        }

        long long operations = static_cast<long long>(k1) + k2;

        if (operations >= totalDiff)
        {
            return 0;
        }

        for (int diff = maxDiff; diff > 0 && operations > 0; diff--)
        {
            if (count[diff] == 0)
            {
                continue;
            }

            long long moved = min(count[diff], operations);

            count[diff] -= moved;
            count[diff - 1] += moved;
            operations -= moved;
        }

        long long retVal = 0;

        for (int diff = 1; diff <= maxDiff; diff++)
        {
            retVal += count[diff] * static_cast<long long>(diff) * diff;
        }

        return retVal;
    }
};
