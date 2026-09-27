//*****************************************************************************
//** 1520. Maximum Number of Non-Overlapping Substrings             leetcode **
//*****************************************************************************

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
typedef struct
{
    int start;
    int end;
} Interval;

static int compareIntervals(const void *a, const void *b)
{
    const Interval *left = (const Interval *)a;
    const Interval *right = (const Interval *)b;

    if (left->end != right->end)
    {
        return left->end - right->end;
    }

    return right->start - left->start;
}

char** maxNumOfSubstrings(char* s, int* returnSize)
{
    int first[26];
    int last[26];
    int n = (int)strlen(s);

    Interval intervals[26];
    int intervalCount = 0;

    *returnSize = 0;

    for (int i = 0; i < 26; i++)
    {
        first[i] = n;
        last[i] = -1;
    }

    for (int i = 0; i < n; i++)
    {
        int c = s[i] - 'a';

        if (first[c] == n)
        {
            first[c] = i;
        }

        last[c] = i;
    }

    for (int c = 0; c < 26; c++)
    {
        if (first[c] == n)
        {
            continue;
        }

        int start = first[c];
        int end = last[c];
        bool valid = true;

        for (int i = start; i <= end; i++)
        {
            int current = s[i] - 'a';

            if (first[current] < start)
            {
                valid = false;
                break;
            }

            if (last[current] > end)
            {
                end = last[current];
            }
        }

        if (valid)
        {
            intervals[intervalCount].start = start;
            intervals[intervalCount].end = end;
            intervalCount++;
        }
    }

    qsort(
        intervals,
        intervalCount,
        sizeof(Interval),
        compareIntervals
    );

    char **retVal = malloc(sizeof(char *) * 26);

    int previousEnd = -1;

    for (int i = 0; i < intervalCount; i++)
    {
        int start = intervals[i].start;
        int end = intervals[i].end;

        if (start > previousEnd)
        {
            int length = end - start + 1;

            retVal[*returnSize] = malloc(sizeof(char) * (length + 1));

            memcpy(
                retVal[*returnSize],
                s + start,
                length
            );

            retVal[*returnSize][length] = '\0';

            (*returnSize)++;

            previousEnd = end;
        }
    }

    return retVal;
}