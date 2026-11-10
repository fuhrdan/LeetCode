class Solution
{
public:
    int climbStairs(int n, vector<int>& costs)
    {
        const long long INF = LLONG_MAX / 4;
        long long dp[4] = {0, INF, INF, INF};

        for (int step = 1; step <= n; step++)
        {
            long long best = INF;

            for (int jump = 1; jump <= 3; jump++)
            {
                int previous = step - jump;

                if (previous < 0)
                {
                    continue;
                }

                best = min(
                    best,
                    dp[previous % 4]
                    + 1LL * jump * jump);
            }

            dp[step % 4] =
                best + costs[step - 1];
        }

        return static_cast<int>(dp[n % 4]);
    }
};
