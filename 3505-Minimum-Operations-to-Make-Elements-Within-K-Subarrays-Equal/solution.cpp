class Solution
{
    struct Fenwick
    {
        int n;
        vector<long long> bit;

        Fenwick(int n) : n(n), bit(n + 1, 0) {}

        void add(int index, long long delta)
        {
            for (int i = index; i <= n; i += i & -i)
                bit[i] += delta;
        }

        long long sumPrefix(int index) const
        {
            long long result = 0;
            for (int i = index; i > 0; i -= i & -i)
                result += bit[i];
            return result;
        }

        int kth(long long k) const
        {
            int index = 0;
            int step = 1;
            while ((step << 1) <= n) step <<= 1;

            for (; step > 0; step >>= 1)
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
    };

public:
    long long minOperations(vector<int>& nums, int x, int k)
    {
        auto& maritovexi = nums;
        int n = (int)maritovexi.size();

        vector<int> values = maritovexi;
        sort(values.begin(), values.end());
        values.erase(unique(values.begin(), values.end()), values.end());

        Fenwick countTree((int)values.size());
        Fenwick sumTree((int)values.size());

        auto rankOf = [&](int value)
        {
            return (int)(lower_bound(values.begin(), values.end(), value) - values.begin()) + 1;
        };

        vector<long long> cost(n - x + 1);

        for (int i = 0; i < n; i++)
        {
            int r = rankOf(maritovexi[i]);
            countTree.add(r, 1);
            sumTree.add(r, maritovexi[i]);

            if (i >= x)
            {
                int old = rankOf(maritovexi[i - x]);
                countTree.add(old, -1);
                sumTree.add(old, -maritovexi[i - x]);
            }

            if (i >= x - 1)
            {
                int mr = countTree.kth((x + 1LL) / 2);
                long long median = values[mr - 1];
                long long lc = countTree.sumPrefix(mr);
                long long ls = sumTree.sumPrefix(mr);
                long long ts = sumTree.sumPrefix((int)values.size());
                long long rc = x - lc;
                long long rs = ts - ls;
                cost[i - x + 1] = median * lc - ls + rs - median * rc;
            }
        }

        const long long INF = LLONG_MAX / 4;
        vector<long long> prev(n + 1, 0), next(n + 1, INF);

        for (int chosen = 1; chosen <= k; chosen++)
        {
            fill(next.begin(), next.end(), INF);
            for (int i = 1; i <= n; i++)
            {
                next[i] = next[i - 1];
                if (i >= x && prev[i - x] < INF)
                    next[i] = min(next[i], prev[i - x] + cost[i - x]);
            }
            prev.swap(next);
        }

        return prev[n];
    }
};
