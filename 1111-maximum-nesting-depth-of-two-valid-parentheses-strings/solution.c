#include <stdlib.h>
#include <string.h>

int* maxDepthAfterSplit(char* seq, int* returnSize)
{
    int n = strlen(seq);
    int* retVal = malloc(n * sizeof(int));
    int depth = 0;

    for (int i = 0; i < n; i++)
    {
        if (seq[i] == '(')
        {
            retVal[i] = depth & 1;
            depth++;
        }
        else
        {
            depth--;
            retVal[i] = depth & 1;
        }
    }

    *returnSize = n;

    return retVal;
}
