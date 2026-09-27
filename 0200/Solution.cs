public class Solution
{
    private void Flood(char[][] grid, int r, int c)
    {
        if (r < 0 || c < 0 ||
            r >= grid.Length || c >= grid[0].Length ||
            grid[r][c] != '1')
        {
            return;
        }

        grid[r][c] = '0';

        Flood(grid, r + 1, c);
        Flood(grid, r - 1, c);
        Flood(grid, r, c + 1);
        Flood(grid, r, c - 1);
    }

    public int NumIslands(char[][] grid)
    {
        int retVal = 0;

        for (int r = 0; r < grid.Length; r++)
        {
            for (int c = 0; c < grid[0].Length; c++)
            {
                if (grid[r][c] == '1')
                {
                    retVal++;
                    Flood(grid, r, c);
                }
            }
        }

        return retVal;
    }
}
