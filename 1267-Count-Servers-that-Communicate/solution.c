#include <stdlib.h>

int countServers(int** grid, int gridSize, int* gridColSize)
{
    int rows = gridSize;
    int cols = gridColSize[0];

    int* rowCount = (int*)calloc(rows, sizeof(int));
    int* colCount = (int*)calloc(cols, sizeof(int));

    if (rowCount == NULL || colCount == NULL)
    {
        free(rowCount);
        free(colCount);
        return 0;
    }

    for (int row = 0; row < rows; row++)
    {
        for (int col = 0; col < cols; col++)
        {
            if (grid[row][col] == 1)
            {
                rowCount[row]++;
                colCount[col]++;
            }
        }
    }

    int retVal = 0;

    for (int row = 0; row < rows; row++)
    {
        for (int col = 0; col < cols; col++)
        {
            if (grid[row][col] == 1
                && (rowCount[row] > 1 || colCount[col] > 1))
            {
                retVal++;
            }
        }
    }

    free(rowCount);
    free(colCount);
    return retVal;
}
