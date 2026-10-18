#include <stdlib.h>

#define MOD 1000000007LL

static long long** combinations;

static long long countWays(int* nums, int size)
{
    if (size <= 2)
    {
        return 1;
    }

    int root = nums[0];
    int* left = (int*)malloc(sizeof(int) * (size - 1));
    int* right = (int*)malloc(sizeof(int) * (size - 1));

    if (left == NULL || right == NULL)
    {
        free(left);
        free(right);
        return 0;
    }

    int leftSize = 0;
    int rightSize = 0;

    for (int i = 1; i < size; i++)
    {
        if (nums[i] < root)
        {
            left[leftSize++] = nums[i];
        }
        else
        {
            right[rightSize++] = nums[i];
        }
    }

    long long leftWays = countWays(left, leftSize);
    long long rightWays = countWays(right, rightSize);

    long long retVal = combinations[leftSize + rightSize][leftSize];
    retVal = (retVal * leftWays) % MOD;
    retVal = (retVal * rightWays) % MOD;

    free(left);
    free(right);

    return retVal;
}

int numOfWays(int* nums, int numsSize)
{
    combinations = (long long**)malloc(sizeof(long long*) * (numsSize + 1));

    if (combinations == NULL)
    {
        return 0;
    }

    for (int i = 0; i <= numsSize; i++)
    {
        combinations[i] = (long long*)calloc((size_t)numsSize + 1, sizeof(long long));

        if (combinations[i] == NULL)
        {
            for (int j = 0; j < i; j++)
            {
                free(combinations[j]);
            }

            free(combinations);
            combinations = NULL;
            return 0;
        }
    }

    for (int i = 0; i <= numsSize; i++)
    {
        combinations[i][0] = 1;
        combinations[i][i] = 1;

        for (int j = 1; j < i; j++)
        {
            combinations[i][j] =
                (combinations[i - 1][j - 1] + combinations[i - 1][j]) % MOD;
        }
    }

    long long totalWays = countWays(nums, numsSize);
    int retVal = (int)((totalWays - 1 + MOD) % MOD);

    for (int i = 0; i <= numsSize; i++)
    {
        free(combinations[i]);
    }

    free(combinations);
    combinations = NULL;

    return retVal;
}
