//*****************************************************************************
//** 6. Zigzag Conversion                                           leetcode **
//*****************************************************************************

char* convert(char* s, int numRows)
{
    int length = strlen(s);

    if (numRows == 1 || numRows >= length)
    {
        char* retVal = malloc((length + 1) * sizeof(char));

        if (retVal == NULL)
        {
            return NULL;
        }

        strcpy(retVal, s);
        return retVal;
    }

    char* retVal = malloc((length + 1) * sizeof(char));

    if (retVal == NULL)
    {
        return NULL;
    }

    int cycleLength = 2 * numRows - 2;
    int index = 0;

    for (int row = 0; row < numRows; row++)
    {
        for (int i = row; i < length; i += cycleLength)
        {
            retVal[index++] = s[i];

            int diagonal = i + cycleLength - 2 * row;

            if (row != 0 &&
                row != numRows - 1 &&
                diagonal < length)
            {
                retVal[index++] = s[diagonal];
            }
        }
    }

    retVal[index] = '\0';

    return retVal;
}