class Solution
{
    public int findMaxForm(String[] strs, int m, int n)
    {
        int[][] dp = new int[m + 1][n + 1];

        for (String s : strs)
        {
            int zeroes = 0;
            int ones = 0;

            for (int i = 0; i < s.length(); i++)
            {
                if (s.charAt(i) == '0')
                {
                    zeroes++;
                }
                else
                {
                    ones++;
                }
            }

            for (int z = m; z >= zeroes; z--)
            {
                for (int o = n; o >= ones; o--)
                {
                    dp[z][o] = Math.max(
                        dp[z][o],
                        dp[z - zeroes][o - ones] + 1);
                }
            }
        }

        return dp[m][n];
    }
}
