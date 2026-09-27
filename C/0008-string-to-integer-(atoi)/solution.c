//*****************************************************************************
//** 8. String to Integer (atoi)                                    leetcode **
//*****************************************************************************

int myAtoi(char* s)
{
    int index = 0;
    int sign = 1;
    int retVal = 0;

    while (s[index] == ' ')
    {
        index++;
    }

    if (s[index] == '-' || s[index] == '+')
    {
        if (s[index] == '-')
        {
            sign = -1;
        }

        index++;
    }

    while (s[index] >= '0' && s[index] <= '9')
    {
        int digit = s[index] - '0';

        if (sign == 1)
        {
            if (retVal > INT_MAX / 10 ||
                (retVal == INT_MAX / 10 && digit > 7))
            {
                return INT_MAX;
            }

            retVal = retVal * 10 + digit;
        }
        else
        {
            if (retVal < INT_MIN / 10 ||
                (retVal == INT_MIN / 10 && digit > 8))
            {
                return INT_MIN;
            }

            retVal = retVal * 10 - digit;
        }

        index++;
    }

    return retVal;
}