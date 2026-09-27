//*****************************************************************************
//** 10. Regular Expression Matching                                leetcode **
//*****************************************************************************

/*
bool isMatchHelper(char* s, char* p, int i, int j)
{
    if (j == strlen(p))
    {
        return i == strlen(s);
    }

    bool firstMatch = (i < strlen(s) && (p[j] == s[i] || p[j] == '.'));

    if (j + 1 < strlen(p) && p[j + 1] == '*')
    {
        return (isMatchHelper(s, p, i, j + 2) || (firstMatch && isMatchHelper(s, p, i + 1, j)));
    }
    else
    {
        return firstMatch && isMatchHelper(s, p, i + 1, j + 1);
    }
}

bool isMatch(char* s, char* p)
{
    return isMatchHelper(s, p, 0, 0);
}
*/

int dp[21][21]; // dp array to store intermediate results

bool dpMatch(char* s, char* p, int i, int j) {
    if (dp[i][j] != -1) {
        return dp[i][j];
    }

    if (j == strlen(p)) {
        return dp[i][j] = (i == strlen(s));
    }

    bool firstMatch = (i < strlen(s) && (p[j] == s[i] || p[j] == '.'));

    if (j + 1 < strlen(p) && p[j + 1] == '*') {
        dp[i][j] = (dpMatch(s, p, i, j + 2) || (firstMatch && dpMatch(s, p, i + 1, j)));
    } else {
        dp[i][j] = firstMatch && dpMatch(s, p, i + 1, j + 1);
    }

    return dp[i][j];
}

bool isMatch(char* s, char* p) {
    // Initialize dp array with -1
    for (int i = 0; i < 21; i++) {
        for (int j = 0; j < 21; j++) {
            dp[i][j] = -1;
        }
    }
    return dpMatch(s, p, 0, 0);
}
