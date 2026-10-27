#include <stdlib.h>
#include <string.h>

char** createGrid(int m, int n, int* returnSize)
{
    char** grid = (char**)malloc(sizeof(char*) * m);

    if (grid == NULL)
    {
        *returnSize = 0;
        return NULL;
    }

    for (int row = 0; row < m; row++)
    {
        grid[row] = (char*)malloc((size_t)n + 1);

        if (grid[row] == NULL)
        {
            for (int i = 0; i < row; i++)
            {
                free(grid[i]);
            }

            free(grid);
            *returnSize = 0;
            return NULL;
        }

        memset(grid[row], '#', n);
        grid[row][n] = '\0';
    }

    for (int col = 0; col < n; col++)
    {
        grid[0][col] = '.';
    }

    for (int row = 0; row < m; row++)
    {
        grid[row][n - 1] = '.';
    }

    *returnSize = m;
    return grid;
}
