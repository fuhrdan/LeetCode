int compare(const void *a, const void *b) {
    int x = *(const int *)a;
    int y = *(const int *)b;
    return (x > y) - (x < y);
}

int maxSelectedElements(int* nums, int numsSize) {
    qsort(nums, numsSize, sizeof(int), compare);

    int maxVal = nums[numsSize - 1];

    int *dp = calloc((size_t)maxVal + 2, sizeof(int));

    if (dp == NULL)
        return 0;

    int result = 0;

    for (int i = 0; i < numsSize; i++) {
        int x = nums[i];

        if (dp[x + 1] < dp[x] + 1)
            dp[x + 1] = dp[x] + 1;

        if (dp[x] < dp[x - 1] + 1)
            dp[x] = dp[x - 1] + 1;

        if (dp[x] > result)
            result = dp[x];

        if (dp[x + 1] > result)
            result = dp[x + 1];
    }

    free(dp);
    return result;
}