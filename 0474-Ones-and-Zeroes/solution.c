#include <stdlib.h>

int findMaxForm(char** strs, int strsSize, int m, int n)
{
    int** dp = (int**)malloc(sizeof(int*) * (m + 1));

    if (dp == NULL)
    {
        return 0;
    }

    for (int i = 0; i <= m; i++)
    {
        dp[i] = (int*)calloc((size_t)n + 1, sizeof(int));

        if (dp[i] == NULL)
        {
            for (int j = 0; j < i; j++)
            {
                free(dp[j]);
            }

            free(dp);
            return 0;
        }
    }

    for (int i = 0; i < strsSize; i++)
    {
        int zeroes = 0;
        int ones = 0;

        for (int j = 0; strs[i][j] != '\0'; j++)
        {
            if (strs[i][j] == '0')
            {
                zeroes++;
            }
            else
            {
                ones++;
            }
        }

        for (int z = m; z >= zeroes; z--)
        {
            for (int o = n; o >= ones; o--)
            {
                int candidate = dp[z - zeroes][o - ones] + 1;

                if (candidate > dp[z][o])
                {
                    dp[z][o] = candidate;
                }
            }
        }
    }

    int retVal = dp[m][n];

    for (int i = 0; i <= m; i++)
    {
        free(dp[i]);
    }

    free(dp);

    return retVal;
}
