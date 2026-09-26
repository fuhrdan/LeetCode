//*****************************************************************************
//** 1621. Number of Sets of K Non-Overlapping Line Segments        leetcode **
//*****************************************************************************

int numberOfSets(int n, int k)
{
    const long long MOD = 1000000007LL;

    int total = n + k - 1;
    int choose = 2 * k;

    if (choose > total)
    {
        return 0;
    }

    long long numerator = 1;
    long long denominator = 1;

    for (int i = 1; i <= choose; i++)
    {
        numerator = (numerator * (total - choose + i)) % MOD;
        denominator = (denominator * i) % MOD;
    }

    long long base = denominator;
    long long exponent = MOD - 2;
    long long inverse = 1;

    while (exponent > 0)
    {
        if (exponent & 1)
        {
            inverse = (inverse * base) % MOD;
        }

        base = (base * base) % MOD;
        exponent >>= 1;
    }

    long long retVal = (numerator * inverse) % MOD;

    return (int)retVal;
}