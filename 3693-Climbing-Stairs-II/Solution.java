class Solution
{
    public int climbStairs(int n, int[] costs)
    {
        final long INF = Long.MAX_VALUE / 4;

        long[] dp =
        {
            0,
            INF,
            INF,
            INF
        };

        for (int step = 1; step <= n; step++)
        {
            long best = INF;

            for (int jump = 1; jump <= 3; jump++)
            {
                int previous = step - jump;

                if (previous < 0)
                {
                    continue;
                }

                long candidate =
                    dp[previous % 4]
                    + (long)jump * jump;

                best = Math.min(best, candidate);
            }

            dp[step % 4] =
                best + costs[step - 1];
        }

        return (int)dp[n % 4];
    }
}
