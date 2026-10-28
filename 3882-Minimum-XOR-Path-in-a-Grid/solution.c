#include <stdlib.h>

int minCost(int** grid, int gridSize, int* gridColSize)
{
    const int XOR_STATES = 1024;
    int rows = gridSize;
    int cols = gridColSize[0];

    int** molqaviren = grid;

    size_t total =
        (size_t)rows * cols * XOR_STATES;

    unsigned char* dp =
        (unsigned char*)calloc(total, sizeof(unsigned char));

    if (dp == NULL)
    {
        return -1;
    }

    #define DP(r,c,x) \
        dp[(((size_t)(r) * cols + (c)) * XOR_STATES) + (x)]

    DP(0, 0, molqaviren[0][0]) = 1;

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

                if ((row > 0 && DP(row - 1, col, previous))
                    || (col > 0 && DP(row, col - 1, previous)))
                {
                    DP(row, col, x) = 1;
                }
            }
        }
    }

    int answer = -1;

    for (int x = 0; x < XOR_STATES; x++)
    {
        if (DP(rows - 1, cols - 1, x))
        {
            answer = x;
            break;
        }
    }

    #undef DP
    free(dp);

    return answer;
}
