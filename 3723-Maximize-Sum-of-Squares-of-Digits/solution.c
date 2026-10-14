#include <stdlib.h>

char* maxSumOfSquares(int num, int sum)
{
    if (sum > num * 9)
    {
        char* retVal = (char*)malloc(1);

        if (retVal != NULL)
        {
            retVal[0] = '\0';
        }

        return retVal;
    }

    char* retVal = (char*)malloc((size_t)num + 1);

    if (retVal == NULL)
    {
        return NULL;
    }

    int index = 0;
    int fullNines = sum / 9;
    int remainder = sum % 9;

    for (int i = 0; i < fullNines; i++)
    {
        retVal[index++] = '9';
    }

    if (remainder > 0)
    {
        retVal[index++] = (char)('0' + remainder);
    }

    while (index < num)
    {
        retVal[index++] = '0';
    }

    retVal[index] = '\0';

    return retVal;
}
