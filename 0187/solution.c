#include <stdlib.h>
#include <string.h>

char** findRepeatedDnaSequences(char* s, int* returnSize)
{
    int length = strlen(s);

    if (length < 10)
    {
        *returnSize = 0;
        return NULL;
    }

    int cap = 16;
    int count = 0;
    char** retVal = malloc(cap * sizeof(char*));

    for (int i = 0; i + 10 <= length; i++)
    {
        int seenBefore = 0;
        int alreadyAdded = 0;

        for (int j = 0; j < i; j++)
        {
            if (strncmp(s + i, s + j, 10) == 0)
            {
                seenBefore = 1;
                break;
            }
        }

        if (!seenBefore)
        {
            continue;
        }

        for (int j = 0; j < count; j++)
        {
            if (strncmp(retVal[j], s + i, 10) == 0)
            {
                alreadyAdded = 1;
                break;
            }
        }

        if (alreadyAdded)
        {
            continue;
        }

        if (count == cap)
        {
            cap *= 2;
            retVal = realloc(retVal, cap * sizeof(char*));
        }

        retVal[count] = malloc(11);
        memcpy(retVal[count], s + i, 10);
        retVal[count][10] = '\0';
        count++;
    }

    *returnSize = count;
    return retVal;
}
