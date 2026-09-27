#include <stdlib.h>
#include <string.h>
#include <stdio.h>

static int cmp179(const void* a, const void* b)
{
    const char* x = *(const char**)a;
    const char* y = *(const char**)b;
    char xy[32], yx[32];

    snprintf(xy, sizeof(xy), "%s%s", x, y);
    snprintf(yx, sizeof(yx), "%s%s", y, x);

    return strcmp(yx, xy);
}

char* largestNumber(int* nums, int numsSize)
{
    char** parts = malloc(numsSize * sizeof(char*));
    int total = 0;

    for (int i = 0; i < numsSize; i++)
    {
        parts[i] = malloc(16);
        sprintf(parts[i], "%d", nums[i]);
        total += strlen(parts[i]);
    }

    qsort(parts, numsSize, sizeof(char*), cmp179);

    if (parts[0][0] == '0')
    {
        for (int i = 0; i < numsSize; i++)
        {
            free(parts[i]);
        }

        free(parts);

        char* retVal = malloc(2);
        strcpy(retVal, "0");
        return retVal;
    }

    char* retVal = malloc(total + 1);
    retVal[0] = '\0';

    for (int i = 0; i < numsSize; i++)
    {
        strcat(retVal, parts[i]);
        free(parts[i]);
    }

    free(parts);
    return retVal;
}
