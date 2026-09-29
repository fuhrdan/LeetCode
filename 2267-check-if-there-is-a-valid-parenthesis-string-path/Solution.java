class Solution
{
    public boolean hasValidPath(char[][] grid)
    {
        int rows = grid.length;
        int cols = grid[0].length;
        int pathLen = rows + cols - 1;

        if (grid[0][0] != '(' ||
            grid[rows - 1][cols - 1] != ')' ||
            pathLen % 2 != 0)
        {
            return false;
        }

        boolean[][] dp = new boolean[cols][pathLen + 1];
        dp[0][1] = true;

        for (int r = 0; r < rows; r++)
        {
            for (int c = 0; c < cols; c++)
            {
                if (r == 0 && c == 0)
                {
                    continue;
                }

                boolean[] next = new boolean[pathLen + 1];
                int delta = grid[r][c] == '(' ? 1 : -1;

                if (r > 0)
                {
                    for (int balance = 0; balance <= pathLen; balance++)
                    {
                        if (dp[c][balance])
                        {
                            int newBalance = balance + delta;

                            if (newBalance >= 0 && newBalance <= pathLen)
                            {
                                next[newBalance] = true;
                            }
                        }
                    }
                }

                if (c > 0)
                {
                    for (int balance = 0; balance <= pathLen; balance++)
                    {
                        if (dp[c - 1][balance])
                        {
                            int newBalance = balance + delta;

                            if (newBalance >= 0 && newBalance <= pathLen)
                            {
                                next[newBalance] = true;
                            }
                        }
                    }
                }

                dp[c] = next;
            }
        }

        return dp[cols - 1][0];
    }
}
