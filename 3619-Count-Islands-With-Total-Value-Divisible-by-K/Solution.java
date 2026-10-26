class Solution
{
    public int countIslands(int[][] grid, int k)
    {
        int rows = grid.length;
        int cols = grid[0].length;
        int capacity = rows * cols;

        int[] rowStack = new int[capacity];
        int[] colStack = new int[capacity];

        int[][] directions =
        {
            {-1, 0},
            {1, 0},
            {0, -1},
            {0, 1}
        };

        int retVal = 0;

        for (int row = 0; row < rows; row++)
        {
            for (int col = 0; col < cols; col++)
            {
                if (grid[row][col] <= 0)
                {
                    continue;
                }

                long islandSum = 0;
                int top = 0;

                islandSum += grid[row][col];
                grid[row][col] = 0;

                rowStack[top] = row;
                colStack[top] = col;
                top++;

                while (top > 0)
                {
                    top--;

                    int currentRow = rowStack[top];
                    int currentCol = colStack[top];

                    for (int[] direction : directions)
                    {
                        int nextRow = currentRow + direction[0];
                        int nextCol = currentCol + direction[1];

                        if (nextRow < 0
                            || nextRow >= rows
                            || nextCol < 0
                            || nextCol >= cols
                            || grid[nextRow][nextCol] <= 0)
                        {
                            continue;
                        }

                        islandSum += grid[nextRow][nextCol];
                        grid[nextRow][nextCol] = 0;

                        rowStack[top] = nextRow;
                        colStack[top] = nextCol;
                        top++;
                    }
                }

                if (islandSum % k == 0)
                {
                    retVal++;
                }
            }
        }

        return retVal;
    }
}
