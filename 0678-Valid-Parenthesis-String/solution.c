#include <stdbool.h>

bool checkValidString(char* s)
{
    int low = 0;
    int high = 0;

    for (int i = 0; s[i] != '\0'; i++)
    {
        if (s[i] == '(')
        {
            low++;
            high++;
        }
        else if (s[i] == ')')
        {
            low--;
            high--;
        }
        else
        {
            low--;
            high++;
        }

        if (high < 0)
        {
            return false;
        }

        if (low < 0)
        {
            low = 0;
        }
    }

    bool retVal = (low == 0);
    return retVal;
}
