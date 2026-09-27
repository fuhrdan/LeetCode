//*****************************************************************************
//** 5. Longest Palindromic Substring                               leetcode **
//*****************************************************************************

char* longestPalindrome(char* s)
{
    int length = strlen(s);

    if (length <= 1)
    {
        char* retVal = malloc((length + 1) * sizeof(char));

        if (retVal == NULL)
        {
            return NULL;
        }

        strcpy(retVal, s);
        return retVal;
    }

    int bestStart = 0;
    int bestLength = 1;

    for (int center = 0; center < length; center++)
    {
        int left = center;
        int right = center;

        while (left >= 0 &&
               right < length &&
               s[left] == s[right])
        {
            int currentLength = right - left + 1;

            if (currentLength > bestLength)
            {
                bestStart = left;
                bestLength = currentLength;
            }

            left--;
            right++;
        }

        left = center;
        right = center + 1;

        while (left >= 0 &&
               right < length &&
               s[left] == s[right])
        {
            int currentLength = right - left + 1;

            if (currentLength > bestLength)
            {
                bestStart = left;
                bestLength = currentLength;
            }

            left--;
            right++;
        }
    }

    char* retVal = malloc((bestLength + 1) * sizeof(char));

    if (retVal == NULL)
    {
        return NULL;
    }

    memcpy(retVal, s + bestStart, bestLength);
    retVal[bestLength] = '\0';

    return retVal;
}