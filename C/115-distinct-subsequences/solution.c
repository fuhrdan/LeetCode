//*****************************************************************************
//** 115. Distinct Subsequences                                     leetcode **
//*****************************************************************************

int numDistinct(char* s, char* t)
{
    int sLen = 0;
    int tLen = 0;

    while (s[sLen] != '\0')
    {
        sLen++;
    }

    while (t[tLen] != '\0')
    {
        tLen++;
    }

    if (tLen > sLen)
    {
        return 0;
    }

    int* dp = (int*)calloc(tLen + 1, sizeof(int));

    dp[0] = 1;

    for (int i = 0; i < sLen; i++)
    {
        for (int j = tLen; j >= 1; j--)
        {
            if (s[i] == t[j - 1])
            {
                if (dp[j] > INT_MAX - dp[j - 1])
                {
                    dp[j] = INT_MAX;
                }
                else
                {
                    dp[j] += dp[j - 1];
                }
            }
        }
    }

    int retVal = dp[tLen];

    free(dp);

    return retVal;
}