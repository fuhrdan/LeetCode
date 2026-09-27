class Solution
{
    private void flood(char[][] grid, int r, int c)
    {
        if (r < 0 || c < 0 ||
            r >= grid.length || c >= grid[0].length ||
            grid[r][c] != '1')
        {
            return;
        }

        grid[r][c] = '0';

        flood(grid, r + 1, c);
        flood(grid, r - 1, c);
        flood(grid, r, c + 1);
        flood(grid, r, c - 1);
    }

    public int numIslands(char[][] grid)
    {
        int retVal = 0;

        for (int r = 0; r < grid.length; r++)
        {
            for (int c = 0; c < grid[0].length; c++)
            {
                if (grid[r][c] == '1')
                {
                    retVal++;
                    flood(grid, r, c);
                }
            }
        }

        return retVal;
    }
}
