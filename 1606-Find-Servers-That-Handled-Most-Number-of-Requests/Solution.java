class Solution
{
    private static class Fenwick
    {
        int n;
        int[] bit;

        Fenwick(int n)
        {
            this.n = n;
            this.bit = new int[n + 1];
        }

        void add(int index, int delta)
        {
            for (int i = index; i <= n; i += i & -i)
                bit[i] += delta;
        }

        int sum(int index)
        {
            int result = 0;
            for (int i = index; i > 0; i -= i & -i)
                result += bit[i];
            return result;
        }

        int kth(int k)
        {
            int index = 0;
            int step = Integer.highestOneBit(n);
            for (; step != 0; step >>= 1)
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

    private static class BusyServer
    {
        long freeTime;
        int index;
        BusyServer(long freeTime, int index)
        {
            this.freeTime = freeTime;
            this.index = index;
        }
    }

    public java.util.List<Integer> busiestServers(int k, int[] arrival, int[] load)
    {
        Fenwick available = new Fenwick(k);
        for (int server = 0; server < k; server++)
            available.add(server + 1, 1);

        java.util.PriorityQueue<BusyServer> busy =
            new java.util.PriorityQueue<>((a, b) ->
            {
                if (a.freeTime != b.freeTime)
                    return Long.compare(a.freeTime, b.freeTime);
                return Integer.compare(a.index, b.index);
            });

        int[] handled = new int[k];

        for (int i = 0; i < arrival.length; i++)
        {
            long time = arrival[i];

            while (!busy.isEmpty() && busy.peek().freeTime <= time)
            {
                BusyServer server = busy.poll();
                available.add(server.index + 1, 1);
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
            busy.offer(new BusyServer(time + load[i], server));
        }

        int best = 0;
        for (int count : handled) best = Math.max(best, count);

        java.util.List<Integer> answer = new java.util.ArrayList<>();
        for (int server = 0; server < k; server++)
            if (handled[server] == best)
                answer.add(server);
        return answer;
    }
}
