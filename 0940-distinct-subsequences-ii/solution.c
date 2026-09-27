//*****************************************************************************
//** 940. Distinct Subsequences II                                  leetcode **
//*****************************************************************************

int distinctSubseqII(char* s)
{
    const long long MOD = 1000000007LL;
    long long total = 0;
    long long last[26] = {0};

    for (int i = 0; s[i] != '\0'; i++)
    {
        int index = s[i] - 'a';

        long long added = (total + 1 - last[index] + MOD) % MOD;

        total = (total + added) % MOD;

        last[index] = (last[index] + added) % MOD;
    }

    return (int)total;
}