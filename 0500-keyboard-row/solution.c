#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

static int keyboardRow(char c)
{
    c = (char)tolower((unsigned char)c);

    if (strchr("qwertyuiop", c) != NULL)
    {
        return 1;
    }

    if (strchr("asdfghjkl", c) != NULL)
    {
        return 2;
    }

    return 3;
}

char** findWords(char** words, int wordsSize, int* returnSize)
{
    char** retVal = malloc(wordsSize * sizeof(char*));
    int count = 0;

    for (int i = 0; i < wordsSize; i++)
    {
        if (words[i][0] == '\0')
        {
            continue;
        }

        int row = keyboardRow(words[i][0]);
        bool valid = true;

        for (int j = 1; words[i][j] != '\0'; j++)
        {
            if (keyboardRow(words[i][j]) != row)
            {
                valid = false;
                break;
            }
        }

        if (valid)
        {
            size_t len = strlen(words[i]);
            retVal[count] = malloc(len + 1);
            memcpy(retVal[count], words[i], len + 1);
            count++;
        }
    }

    *returnSize = count;
    return retVal;
}
