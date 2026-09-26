//*****************************************************************************
//** 3414. Maximum Score of Non-overlapping Intervals               leetcode **
//*****************************************************************************

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
typedef struct
{
    int left;
    int right;
    int weight;
    int originalIndex;
} Interval;

typedef struct
{
    long long score;
    int indices[4];
    int valid;
} State;

static int compareIntervals(const void* a, const void* b)
{
    const Interval* x = (const Interval*)a;
    const Interval* y = (const Interval*)b;

    if (x->right < y->right)
    {
        return -1;
    }

    if (x->right > y->right)
    {
        return 1;
    }

    if (x->left < y->left)
    {
        return -1;
    }

    if (x->left > y->left)
    {
        return 1;
    }

    if (x->originalIndex < y->originalIndex)
    {
        return -1;
    }

    if (x->originalIndex > y->originalIndex)
    {
        return 1;
    }

    return 0;
}

static int compareLex(const int* a, int aSize,
                      const int* b, int bSize)
{
    int minSize = (aSize < bSize) ? aSize : bSize;

    for (int i = 0; i < minSize; i++)
    {
        if (a[i] < b[i])
        {
            return -1;
        }

        if (a[i] > b[i])
        {
            return 1;
        }
    }

    if (aSize < bSize)
    {
        return -1;
    }

    if (aSize > bSize)
    {
        return 1;
    }

    return 0;
}

static void insertSorted(int* destination,
                         const int* source,
                         int sourceSize,
                         int value)
{
    int sourceIndex = 0;
    int destinationIndex = 0;

    while (sourceIndex < sourceSize &&
           source[sourceIndex] < value)
    {
        destination[destinationIndex] = source[sourceIndex];
        sourceIndex++;
        destinationIndex++;
    }

    destination[destinationIndex] = value;
    destinationIndex++;

    while (sourceIndex < sourceSize)
    {
        destination[destinationIndex] = source[sourceIndex];
        sourceIndex++;
        destinationIndex++;
    }
}

int* maximumWeight(int** intervals, int intervalsSize,
                   int* intervalsColSize, int* returnSize)
{
    (void)intervalsColSize;

    Interval* sorted =
        (Interval*)malloc(sizeof(Interval) * intervalsSize);

    for (int i = 0; i < intervalsSize; i++)
    {
        sorted[i].left = intervals[i][0];
        sorted[i].right = intervals[i][1];
        sorted[i].weight = intervals[i][2];
        sorted[i].originalIndex = i;
    }

    qsort(sorted,
          intervalsSize,
          sizeof(Interval),
          compareIntervals);

    State (*dp)[5] =
        (State(*)[5])malloc(sizeof(State) *
                            (intervalsSize + 1) * 5);

    for (int i = 0; i <= intervalsSize; i++)
    {
        for (int count = 0; count <= 4; count++)
        {
            dp[i][count].score = LLONG_MIN;
            dp[i][count].valid = 0;

            for (int j = 0; j < 4; j++)
            {
                dp[i][count].indices[j] = 0;
            }
        }

        dp[i][0].score = 0;
        dp[i][0].valid = 1;
    }

    for (int i = 1; i <= intervalsSize; i++)
    {
        Interval current = sorted[i - 1];

        int low = 0;
        int high = i - 1;

        while (low < high)
        {
            int mid = low + (high - low) / 2;

            if (sorted[mid].right < current.left)
            {
                low = mid + 1;
            }
            else
            {
                high = mid;
            }
        }

        int compatibleCount;

        if (i == 1 || sorted[low].right >= current.left)
        {
            compatibleCount = low;
        }
        else
        {
            compatibleCount = low + 1;
        }

        if (i == 1)
        {
            compatibleCount = 0;
        }
        else
        {
            low = 0;
            high = i - 1;

            while (low < high)
            {
                int mid = low + (high - low) / 2;

                if (sorted[mid].right < current.left)
                {
                    low = mid + 1;
                }
                else
                {
                    high = mid;
                }
            }

            if (sorted[low].right < current.left)
            {
                compatibleCount = low + 1;
            }
            else
            {
                compatibleCount = low;
            }
        }

        for (int count = 1; count <= 4; count++)
        {
            dp[i][count] = dp[i - 1][count];

            if (dp[compatibleCount][count - 1].valid)
            {
                State candidate;

                candidate.valid = 1;

                candidate.score =
                    dp[compatibleCount][count - 1].score +
                    current.weight;

                insertSorted(candidate.indices,
                             dp[compatibleCount][count - 1].indices,
                             count - 1,
                             current.originalIndex);

                int takeCandidate = 0;

                if (!dp[i][count].valid)
                {
                    takeCandidate = 1;
                }
                else if (candidate.score > dp[i][count].score)
                {
                    takeCandidate = 1;
                }
                else if (candidate.score == dp[i][count].score)
                {
                    if (compareLex(candidate.indices,
                                   count,
                                   dp[i][count].indices,
                                   count) < 0)
                    {
                        takeCandidate = 1;
                    }
                }

                if (takeCandidate)
                {
                    dp[i][count] = candidate;
                }
            }
        }
    }

    State best;
    best.score = LLONG_MIN;
    best.valid = 0;

    int bestCount = 0;

    for (int count = 0; count <= 4; count++)
    {
        if (!dp[intervalsSize][count].valid)
        {
            continue;
        }

        int take = 0;

        if (!best.valid)
        {
            take = 1;
        }
        else if (dp[intervalsSize][count].score > best.score)
        {
            take = 1;
        }
        else if (dp[intervalsSize][count].score == best.score)
        {
            if (compareLex(dp[intervalsSize][count].indices,
                           count,
                           best.indices,
                           bestCount) < 0)
            {
                take = 1;
            }
        }

        if (take)
        {
            best = dp[intervalsSize][count];
            bestCount = count;
        }
    }

    int* retVal = (int*)malloc(sizeof(int) * bestCount);

    for (int i = 0; i < bestCount; i++)
    {
        retVal[i] = best.indices[i];
    }

    *returnSize = bestCount;

    free(dp);
    free(sorted);

    return retVal;
}