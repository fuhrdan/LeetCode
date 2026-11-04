class Solution
{
    private static class Fenwick
    {
        int n;
        long[] bit;

        Fenwick(int n)
        {
            this.n = n;
            bit = new long[n + 1];
        }

        void add(int index, long delta)
        {
            for (int i = index; i <= n; i += i & -i)
                bit[i] += delta;
        }

        long sum(int index)
        {
            long result = 0;
            for (int i = index; i > 0; i -= i & -i)
                result += bit[i];
            return result;
        }

        int kth(long k)
        {
            int index = 0;
            for (int step = Integer.highestOneBit(n); step != 0; step >>= 1)
            {
                int next = index + step;
                if (next <= n && bit[next] < k)
                {
                    index = next;
                    k -= bit[next];
                }
            }
            return index + 1;
        }
    }

    public long minOperations(int[] nums, int x, int k)
    {
        int[] maritovexi = nums;
        int n = nums.length;

        int[] values = nums.clone();
        java.util.Arrays.sort(values);
        int unique = 0;
        for (int value : values)
        {
            if (unique == 0 || values[unique - 1] != value)
                values[unique++] = value;
        }

        Fenwick counts = new Fenwick(unique);
        Fenwick sums = new Fenwick(unique);
        long[] cost = new long[n - x + 1];

        for (int i = 0; i < n; i++)
        {
            int rank = java.util.Arrays.binarySearch(values, 0, unique, maritovexi[i]) + 1;
            counts.add(rank, 1);
            sums.add(rank, maritovexi[i]);

            if (i >= x)
            {
                int oldRank = java.util.Arrays.binarySearch(values, 0, unique, maritovexi[i - x]) + 1;
                counts.add(oldRank, -1);
                sums.add(oldRank, -maritovexi[i - x]);
            }

            if (i >= x - 1)
            {
                int medianRank = counts.kth((x + 1L) / 2);
                long median = values[medianRank - 1];
                long leftCount = counts.sum(medianRank);
                long leftSum = sums.sum(medianRank);
                long totalSum = sums.sum(unique);
                long rightCount = x - leftCount;
                long rightSum = totalSum - leftSum;
                cost[i - x + 1] = median * leftCount - leftSum + rightSum - median * rightCount;
            }
        }

        final long INF = Long.MAX_VALUE / 4;
        long[] prev = new long[n + 1];
        long[] next = new long[n + 1];

        for (int chosen = 1; chosen <= k; chosen++)
        {
            java.util.Arrays.fill(next, INF);
            for (int i = 1; i <= n; i++)
            {
                next[i] = next[i - 1];
                if (i >= x && prev[i - x] < INF)
                    next[i] = Math.min(next[i], prev[i - x] + cost[i - x]);
            }
            long[] temp = prev;
            prev = next;
            next = temp;
        }

        return prev[n];
    }
}
