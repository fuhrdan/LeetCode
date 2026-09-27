//*****************************************************************************
//** 3483. Unique 3-Digit Even Numbers                              leetcode **
//*****************************************************************************

int totalNumbers(int* digits, int digitsSize)
{
    bool seen[1000] = { false };
    int retVal = 0;

    for (int i = 0; i < digitsSize; i++)
    {
        if (digits[i] == 0)
        {
            continue;
        }

        for (int j = 0; j < digitsSize; j++)
        {
            if (j == i)
            {
                continue;
            }

            for (int k = 0; k < digitsSize; k++)
            {
                if (k == i || k == j)
                {
                    continue;
                }

                if (digits[k] % 2 != 0)
                {
                    continue;
                }

                int number = digits[i] * 100 +
                             digits[j] * 10 +
                             digits[k];

                if (!seen[number])
                {
                    seen[number] = true;
                    retVal++;
                }
            }
        }
    }

    return retVal;
}