#include <stdlib.h>

int uniquePaths(int** grid, int gridSize, int* gridColSize)
{
    const int MOD = 1000000007;
    int rows = gridSize;
    int cols = gridColSize[0];

    long long* down =
        (long long*)calloc(cols, sizeof(long long));

    if (down == NULL)
    {
        return 0;
    }

    down[0] = 1;
    long long left = 0;

    for (int row = 0; row < rows; row++)
    {
        left = 0;

        for (int col = 0; col < cols; col++)
        {
            if (grid[row][col] == 1)
            {
                long long temp = left;
                left = down[col];
                down[col] = temp;
            }
            else
            {
                long long total =
                    (left + down[col]) % MOD;

                left = total;
                down[col] = total;
            }
        }
    }

    free(down);
    return (int)left;
}
