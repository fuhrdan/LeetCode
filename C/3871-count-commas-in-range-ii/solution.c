//*****************************************************************************
//** 3871. Count Commas in Range II                                 leetcode **
//*****************************************************************************
long long countCommas(long long n)
{
    long long commacommachameleon = 0;
    long long comma = 1000;

    while (comma <= n)
    {
        commacommachameleon = commacommachameleon + (n - comma + 1);

        if (comma > n / 1000)
        {
            break;
        }

        comma = comma * 1000;
    }

    return commacommachameleon;
}