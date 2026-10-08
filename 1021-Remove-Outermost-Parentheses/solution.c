#include <stdlib.h>
#include <string.h>

char* removeOuterParentheses(char* s)
{
    size_t length = strlen(s);
    char* result = (char*)malloc(length + 1);

    if (result == NULL)
    {
        return NULL;
    }

    int depth = 0;
    size_t writeIndex = 0;

    for (size_t i = 0; i < length; i++)
    {
        if (s[i] == '(')
        {
            if (depth > 0)
            {
                result[writeIndex++] = s[i];
            }

            depth++;
        }
        else
        {
            depth--;

            if (depth > 0)
            {
                result[writeIndex++] = s[i];
            }
        }
    }

    result[writeIndex] = '\0';

    return result;
}
