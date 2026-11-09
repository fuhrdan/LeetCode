class Solution
{
    struct Fenwick
    {
        int n;
        vector<int> bit;

        Fenwick(int n) : n(n), bit(n + 1, 0) {}

        void add(int index, int delta)
        {
            for (int i = index; i <= n; i += i & -i)
                bit[i] += delta;
        }

        int sum(int index) const
        {
            int result = 0;
            for (int i = index; i > 0; i -= i & -i)
                result += bit[i];
            return result;
        }

        int kth(int k) const
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
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load)
    {
        Fenwick available(k);
        for (int server = 0; server < k; server++)
            available.add(server + 1, 1);

        using Busy = pair<long long, int>;
        priority_queue<Busy, vector<Busy>, greater<Busy>> busy;
        vector<int> handled(k, 0);

        for (int i = 0; i < (int)arrival.size(); i++)
        {
            long long time = arrival[i];

            while (!busy.empty() && busy.top().first <= time)
            {
                int server = busy.top().second;
                busy.pop();
                available.add(server + 1, 1);
            }

            int totalFree = available.sum(k);
            if (totalFree == 0) continue;

            int start = i % k;
            int beforeStart = available.sum(start);
            int targetOrder = (totalFree - beforeStart > 0) ? beforeStart + 1 : 1;
            int fenwickIndex = available.kth(targetOrder);
            int server = fenwickIndex - 1;

            available.add(fenwickIndex, -1);
            handled[server]++;
            busy.push({time + load[i], server});
        }

        int best = *max_element(handled.begin(), handled.end());
        vector<int> answer;
        for (int server = 0; server < k; server++)
            if (handled[server] == best)
                answer.push_back(server);
        return answer;
    }
};
