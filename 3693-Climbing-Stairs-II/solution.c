#include <limits.h>

int climbStairs(int n, int* costs, int costsSize)
{
    (void)costsSize;

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

            long long candidate =
                dp[previous % 4]
                + (long long)jump * jump;

            if (candidate < best)
            {
                best = candidate;
            }
        }

        dp[step % 4] =
            best + costs[step - 1];
    }

    return (int)dp[n % 4];
}
