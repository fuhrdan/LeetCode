#include <stdlib.h>

#define LOG 18

static long long adjustedSum(
    int l,
    int r,
    int* nums,
    int* up,
    long long* sum)
{
    int target = r + 1;
    int cur = l;
    long long ans = 0;

    for (int b = LOG - 1; b >= 0 && cur < target; --b)
    {
        int nxt = up[cur * LOG + b];

        if (nxt <= target)
        {
            ans += sum[cur * LOG + b];
            cur = nxt;
        }
    }

    if (cur < target)
    {
        ans += (long long)nums[cur] * (target - cur);
    }

    return ans;
}

long long countNonDecreasingSubarrays(
    int* nums,
    int numsSize,
    int k)
{
    int n = numsSize;

    long long* pref =
        (long long*)malloc(sizeof(long long) * (n + 1));

    int* ng =
        (int*)malloc(sizeof(int) * n);

    int* st =
        (int*)malloc(sizeof(int) * n);

    int* up =
        (int*)malloc(sizeof(int) * n * LOG);

    long long* sum =
        (long long*)malloc(sizeof(long long) * n * LOG);

    if (!pref || !ng || !st || !up || !sum)
    {
        free(pref);
        free(ng);
        free(st);
        free(up);
        free(sum);
        return 0;
    }

    pref[0] = 0;

    for (int i = 0; i < n; ++i)
    {
        pref[i + 1] = pref[i] + nums[i];
    }

    int top = 0;

    for (int i = n - 1; i >= 0; --i)
    {
        while (top > 0 && nums[st[top - 1]] <= nums[i])
        {
            --top;
        }

        ng[i] = top > 0 ? st[top - 1] : n;
        st[top++] = i;
    }

    for (int i = 0; i < n; ++i)
    {
        up[i * LOG] = ng[i];
        sum[i * LOG] =
            (long long)nums[i] * (ng[i] - i);
    }

    for (int b = 1; b < LOG; ++b)
    {
        for (int i = 0; i < n; ++i)
        {
            int mid = up[i * LOG + b - 1];

            if (mid < n)
            {
                up[i * LOG + b] =
                    up[mid * LOG + b - 1];

                sum[i * LOG + b] =
                    sum[i * LOG + b - 1]
                    + sum[mid * LOG + b - 1];
            }
            else
            {
                up[i * LOG + b] = n;
                sum[i * LOG + b] =
                    sum[i * LOG + b - 1];
            }
        }
    }

    long long answer = 0;

    for (int l = 0; l < n; ++l)
    {
        int lo = l;
        int hi = n - 1;
        int best = l;

        while (lo <= hi)
        {
            int mid = lo + (hi - lo) / 2;

            long long raised =
                adjustedSum(l, mid, nums, up, sum);

            long long original =
                pref[mid + 1] - pref[l];

            long long cost =
                raised - original;

            if (cost <= (long long)k)
            {
                best = mid;
                lo = mid + 1;
            }
            else
            {
                hi = mid - 1;
            }
        }

        answer +=
            (long long)(best - l + 1);
    }

    free(pref);
    free(ng);
    free(st);
    free(up);
    free(sum);

    return answer;
}
