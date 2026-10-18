class Solution
{
private:
    static constexpr long long MOD = 1000000007LL;
    vector<vector<long long>> combinations;

    long long countWays(const vector<int>& nums)
    {
        int n = static_cast<int>(nums.size());

        if (n <= 2)
        {
            return 1;
        }

        int root = nums[0];
        vector<int> left;
        vector<int> right;

        for (int i = 1; i < n; i++)
        {
            if (nums[i] < root)
            {
                left.push_back(nums[i]);
            }
            else
            {
                right.push_back(nums[i]);
            }
        }

        long long retVal =
            combinations[left.size() + right.size()][left.size()];

        retVal = (retVal * countWays(left)) % MOD;
        retVal = (retVal * countWays(right)) % MOD;

        return retVal;
    }

public:
    int numOfWays(vector<int>& nums)
    {
        int n = static_cast<int>(nums.size());

        combinations.assign(
            n + 1,
            vector<long long>(n + 1, 0));

        for (int i = 0; i <= n; i++)
        {
            combinations[i][0] = 1;
            combinations[i][i] = 1;

            for (int j = 1; j < i; j++)
            {
                combinations[i][j] =
                    (combinations[i - 1][j - 1]
                    + combinations[i - 1][j]) % MOD;
            }
        }

        long long totalWays = countWays(nums);

        return static_cast<int>((totalWays - 1 + MOD) % MOD);
    }
};
