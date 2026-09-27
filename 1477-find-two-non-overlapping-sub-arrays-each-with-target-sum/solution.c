//*****************************************************************************
//** 1477. Find Two Non-overlapping Sub-arrays Each With Target Sum leetcode **
//*****************************************************************************

int minSumOfLengths(int* arr, int arrSize, int target)
{
    int* best = malloc(sizeof(int) * arrSize);

    if (best == NULL)
    {
        return -1;
    }

    int left = 0;
    long long sum = 0;

    int shortest = INT_MAX;
    int root_beer = INT_MAX;

    for (int right = 0; right < arrSize; right++)
    {
        sum += arr[right];

        while (sum > target && left <= right)
        {
            sum -= arr[left];
            left++;
        }

        if (sum == target)
        {
            int length = right - left + 1;

            /*
             * If there was already a valid subarray ending
             * before this one begins, combine them.
             */
            if (left > 0 && best[left - 1] != INT_MAX)
            {
                int totalLength = length + best[left - 1];

                if (totalLength < root_beer)
                {
                    root_beer = totalLength;
                }
            }

            /*
             * Update the shortest target-sum subarray
             * encountered so far.
             */
            if (length < shortest)
            {
                shortest = length;
            }
        }

        best[right] = shortest;
    }

    free(best);

    if (root_beer == INT_MAX)
    {
        return -1;
    }

    return root_beer;
}