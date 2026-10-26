#include <stdlib.h>

typedef struct
{
    int row;
    int col;
} Cell;

int countIslands(int** grid, int gridSize, int* gridColSize, int k)
{
    int rows = gridSize;
    int cols = gridColSize[0];
    int capacity = rows * cols;

    Cell* stack = (Cell*)malloc(sizeof(Cell) * capacity);

    if (stack == NULL)
    {
        return 0;
    }

    static const int directions[4][2] =
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

            long long islandSum = 0;
            int top = 0;

            islandSum += grid[row][col];
            grid[row][col] = 0;

            stack[top++] = (Cell){row, col};

            while (top > 0)
            {
                Cell current = stack[--top];

                for (int d = 0; d < 4; d++)
                {
                    int nextRow = current.row + directions[d][0];
                    int nextCol = current.col + directions[d][1];

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

                    stack[top++] = (Cell){nextRow, nextCol};
                }
            }

            if (islandSum % k == 0)
            {
                retVal++;
            }
        }
    }

    free(stack);

    return retVal;
}
