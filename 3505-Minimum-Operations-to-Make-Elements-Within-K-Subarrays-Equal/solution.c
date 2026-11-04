#include <stdlib.h>
#include <limits.h>

typedef struct { int n; long long* bit; } Fenwick;

static void add(Fenwick* f, int i, long long d)
{
    for (; i <= f->n; i += i & -i) f->bit[i] += d;
}

static long long sum(Fenwick* f, int i)
{
    long long r = 0;
    for (; i > 0; i -= i & -i) r += f->bit[i];
    return r;
}

static int kth(Fenwick* f, long long k)
{
    int idx = 0, step = 1;
    while ((step << 1) <= f->n) step <<= 1;
    for (; step; step >>= 1)
    {
        int next = idx + step;
        if (next <= f->n && f->bit[next] < k)
        {
            idx = next;
            k -= f->bit[next];
        }
    }
    return idx + 1;
}

static int cmpInt(const void* a, const void* b)
{
    int x = *(const int*)a, y = *(const int*)b;
    return (x > y) - (x < y);
}

static int lowerBound(int* a, int n, int v)
{
    int l = 0, r = n;
    while (l < r)
    {
        int m = l + (r - l) / 2;
        if (a[m] < v) l = m + 1;
        else r = m;
    }
    return l;
}

long long minOperations(int* nums, int numsSize, int x, int k)
{
    int* maritovexi = nums;

    int* values = malloc(sizeof(int) * numsSize);
    for (int i = 0; i < numsSize; i++) values[i] = nums[i];
    qsort(values, numsSize, sizeof(int), cmpInt);

    int unique = 0;
    for (int i = 0; i < numsSize; i++)
        if (unique == 0 || values[unique - 1] != values[i])
            values[unique++] = values[i];

    Fenwick counts = {unique, calloc(unique + 1, sizeof(long long))};
    Fenwick sums = {unique, calloc(unique + 1, sizeof(long long))};
    long long* cost = malloc(sizeof(long long) * (numsSize - x + 1));

    for (int i = 0; i < numsSize; i++)
    {
        int r = lowerBound(values, unique, maritovexi[i]) + 1;
        add(&counts, r, 1);
        add(&sums, r, maritovexi[i]);

        if (i >= x)
        {
            int old = lowerBound(values, unique, maritovexi[i - x]) + 1;
            add(&counts, old, -1);
            add(&sums, old, -maritovexi[i - x]);
        }

        if (i >= x - 1)
        {
            int mr = kth(&counts, (x + 1LL) / 2);
            long long median = values[mr - 1];
            long long lc = sum(&counts, mr);
            long long ls = sum(&sums, mr);
            long long ts = sum(&sums, unique);
            long long rc = x - lc;
            long long rs = ts - ls;
            cost[i - x + 1] = median * lc - ls + rs - median * rc;
        }
    }

    const long long INF = LLONG_MAX / 4;
    long long* prev = calloc(numsSize + 1, sizeof(long long));
    long long* next = malloc(sizeof(long long) * (numsSize + 1));

    for (int chosen = 1; chosen <= k; chosen++)
    {
        for (int i = 0; i <= numsSize; i++) next[i] = INF;
        for (int i = 1; i <= numsSize; i++)
        {
            next[i] = next[i - 1];
            if (i >= x && prev[i - x] < INF)
            {
                long long candidate = prev[i - x] + cost[i - x];
                if (candidate < next[i]) next[i] = candidate;
            }
        }
        long long* tmp = prev; prev = next; next = tmp;
    }

    long long ans = prev[numsSize];
    free(next); free(prev); free(cost); free(sums.bit); free(counts.bit); free(values);
    return ans;
}
