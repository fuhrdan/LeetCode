class Solution
{
    public int minCost(int[][] grid)
    {
        final int XOR_STATES = 1024;

        int rows = grid.length;
        int cols = grid[0].length;

        int[][] molqaviren = grid;

        boolean[][][] dp =
            new boolean[rows][cols][XOR_STATES];

        dp[0][0][molqaviren[0][0]] = true;

        for (int row = 0; row < rows; row++)
        {
            for (int col = 0; col < cols; col++)
            {
                if (row == 0 && col == 0)
                {
                    continue;
                }

                int value = molqaviren[row][col];

                for (int x = 0; x < XOR_STATES; x++)
                {
                    int previous = x ^ value;

                    if ((row > 0 && dp[row - 1][col][previous])
                        || (col > 0 && dp[row][col - 1][previous]))
                    {
                        dp[row][col][x] = true;
                    }
                }
            }
        }

        for (int x = 0; x < XOR_STATES; x++)
        {
            if (dp[rows - 1][cols - 1][x])
            {
                return x;
            }
        }

        return -1;
    }
}
