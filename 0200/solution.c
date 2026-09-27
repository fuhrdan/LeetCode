static void flood(char** grid, int rows, int cols, int r, int c)
{
    if (r < 0 || c < 0 || r >= rows || c >= cols || grid[r][c] != '1')
    {
        return;
    }

    grid[r][c] = '0';

    flood(grid, rows, cols, r + 1, c);
    flood(grid, rows, cols, r - 1, c);
    flood(grid, rows, cols, r, c + 1);
    flood(grid, rows, cols, r, c - 1);
}

int numIslands(char** grid, int gridSize, int* gridColSize)
{
    if (gridSize == 0)
    {
        return 0;
    }

    int cols = gridColSize[0];
    int retVal = 0;

    for (int r = 0; r < gridSize; r++)
    {
        for (int c = 0; c < cols; c++)
        {
            if (grid[r][c] == '1')
            {
                retVal++;
                flood(grid, gridSize, cols, r, c);
            }
        }
    }

    return retVal;
}
