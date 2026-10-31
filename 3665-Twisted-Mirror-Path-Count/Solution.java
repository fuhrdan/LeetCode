class Solution
{
    public int uniquePaths(int[][] grid)
    {
        final int MOD = 1_000_000_007;

        int rows = grid.length;
        int cols = grid[0].length;

        long[] down = new long[cols];
        down[0] = 1;

        long left = 0;

        for (int row = 0; row < rows; row++)
        {
            left = 0;

            for (int col = 0; col < cols; col++)
            {
                if (grid[row][col] == 1)
                {
                    long temp = left;
                    left = down[col];
                    down[col] = temp;
                }
                else
                {
                    long total =
                        (left + down[col]) % MOD;

                    left = total;
                    down[col] = total;
                }
            }
        }

        return (int)left;
    }
}
