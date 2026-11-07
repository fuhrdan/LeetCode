class Solution
{
    static class FreeServer
    {
        int weight, index;

        FreeServer(int weight, int index)
        {
            this.weight = weight;
            this.index = index;
        }
    }

    static class BusyServer
    {
        long freeTime;
        int weight, index;

        BusyServer(long freeTime, int weight, int index)
        {
            this.freeTime = freeTime;
            this.weight = weight;
            this.index = index;
        }
    }

    public int[] assignTasks(int[] servers, int[] tasks)
    {
        java.util.PriorityQueue<FreeServer> freeServers =
            new java.util.PriorityQueue<>((a, b) ->
            {
                if (a.weight != b.weight)
                    return Integer.compare(a.weight, b.weight);
                return Integer.compare(a.index, b.index);
            });

        java.util.PriorityQueue<BusyServer> busyServers =
            new java.util.PriorityQueue<>((a, b) ->
            {
                if (a.freeTime != b.freeTime)
                    return Long.compare(a.freeTime, b.freeTime);
                if (a.weight != b.weight)
                    return Integer.compare(a.weight, b.weight);
                return Integer.compare(a.index, b.index);
            });

        for (int i = 0; i < servers.length; i++)
            freeServers.offer(new FreeServer(servers[i], i));

        int[] ans = new int[tasks.length];
        long time = 0;

        for (int i = 0; i < tasks.length; i++)
        {
            time = Math.max(time, i);

            while (!busyServers.isEmpty() && busyServers.peek().freeTime <= time)
            {
                BusyServer s = busyServers.poll();
                freeServers.offer(new FreeServer(s.weight, s.index));
            }

            if (freeServers.isEmpty())
            {
                time = busyServers.peek().freeTime;

                while (!busyServers.isEmpty() && busyServers.peek().freeTime <= time)
                {
                    BusyServer s = busyServers.poll();
                    freeServers.offer(new FreeServer(s.weight, s.index));
                }
            }

            FreeServer s = freeServers.poll();
            ans[i] = s.index;

            busyServers.offer(new BusyServer(
                time + tasks[i],
                s.weight,
                s.index));
        }

        return ans;
    }
}
