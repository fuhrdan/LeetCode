#include <stdbool.h>
#include <stdlib.h>

bool hasValidPath(char** grid, int gridSize, int* gridColSize)
{
    int rows = gridSize;
    int cols = gridColSize[0];
    int pathLen = rows + cols - 1;

    if (grid[0][0] != '(' ||
        grid[rows - 1][cols - 1] != ')' ||
        (pathLen % 2) != 0)
    {
        return false;
    }

    bool** dp = malloc(cols * sizeof(bool*));

    for (int c = 0; c < cols; c++)
    {
        dp[c] = calloc(pathLen + 1, sizeof(bool));
    }

    dp[0][1] = true;

    for (int r = 0; r < rows; r++)
    {
        for (int c = 0; c < cols; c++)
        {
            if (r == 0 && c == 0)
            {
                continue;
            }

            bool* next = calloc(pathLen + 1, sizeof(bool));
            int delta = grid[r][c] == '(' ? 1 : -1;

            if (r > 0)
            {
                for (int balance = 0; balance <= pathLen; balance++)
                {
                    if (dp[c][balance])
                    {
                        int newBalance = balance + delta;

                        if (newBalance >= 0 && newBalance <= pathLen)
                        {
                            next[newBalance] = true;
                        }
                    }
                }
            }

            if (c > 0)
            {
                for (int balance = 0; balance <= pathLen; balance++)
                {
                    if (dp[c - 1][balance])
                    {
                        int newBalance = balance + delta;

                        if (newBalance >= 0 && newBalance <= pathLen)
                        {
                            next[newBalance] = true;
                        }
                    }
                }
            }

            free(dp[c]);
            dp[c] = next;
        }
    }

    bool retVal = dp[cols - 1][0];

    for (int c = 0; c < cols; c++)
    {
        free(dp[c]);
    }

    free(dp);

    return retVal;
}
