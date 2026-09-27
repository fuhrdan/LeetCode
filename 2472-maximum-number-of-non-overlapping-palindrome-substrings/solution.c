//*****************************************************************************
//** 2472. Maximum Number of Non-overlapping Palindrome Substrings  leetcode **
//*****************************************************************************

int maxPalindromes(char* s, int k)
{
    int n = strlen(s);

    unsigned char* palindrome = calloc((size_t)n * n, sizeof(unsigned char));

    int* dp = calloc(n + 1, sizeof(int));

    for (int i = 0; i < n; i++)
    {
        palindrome[i * n + i] = 1;
    }

    for (int len = 2; len <= n; len++)
    {
        for (int start = 0; start + len <= n; start++)
        {
            int end = start + len - 1;

            if (s[start] == s[end])
            {
                if (len == 2 || palindrome[(start + 1) * n + (end - 1)])
                {
                    palindrome[start * n + end] = 1;
                }
            }
        }
    }

    for (int end = 1; end <= n; end++)
    {
        dp[end] = dp[end - 1];

        for (int start = 0; start <= end - k; start++)
        {
            if (palindrome[start * n + (end - 1)])
            {
                int candidate = dp[start] + 1;

                if (candidate > dp[end])
                {
                    dp[end] = candidate;
                }
            }
        }
    }

    int retVal = dp[n];

    free(palindrome);
    free(dp);

    return retVal;
}