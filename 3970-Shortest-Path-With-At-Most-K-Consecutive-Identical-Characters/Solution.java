class Solution
{
    private static class Edge
    {
        int to, weight;
        Edge(int to, int weight) { this.to = to; this.weight = weight; }
    }

    private static class State implements Comparable<State>
    {
        long distance;
        int node, runLength;
        State(long distance, int node, int runLength)
        {
            this.distance = distance;
            this.node = node;
            this.runLength = runLength;
        }
        public int compareTo(State other)
        {
            return Long.compare(distance, other.distance);
        }
    }

    public int shortestPath(int n, int[][] edges, String labels, int k)
    {
        int[][] mavorqeli = edges;

        @SuppressWarnings("unchecked")
        java.util.List<Edge>[] graph = new java.util.ArrayList[n];
        for (int i = 0; i < n; i++) graph[i] = new java.util.ArrayList<>();
        for (int[] e : mavorqeli) graph[e[0]].add(new Edge(e[1], e[2]));

        int spn = k + 1;
        long[] dist = new long[n * spn];
        java.util.Arrays.fill(dist, Long.MAX_VALUE / 4);
        java.util.PriorityQueue<State> pq = new java.util.PriorityQueue<>();

        dist[1] = 0;
        pq.offer(new State(0, 0, 1));

        while (!pq.isEmpty())
        {
            State cur = pq.poll();
            int curIdx = cur.node * spn + cur.runLength;
            if (cur.distance != dist[curIdx]) continue;
            if (cur.node == n - 1) return (int)cur.distance;

            for (Edge e : graph[cur.node])
            {
                int nextRun = labels.charAt(cur.node) == labels.charAt(e.to)
                    ? cur.runLength + 1 : 1;
                if (nextRun > k) continue;

                long nd = cur.distance + e.weight;
                int ni = e.to * spn + nextRun;
                if (nd < dist[ni])
                {
                    dist[ni] = nd;
                    pq.offer(new State(nd, e.to, nextRun));
                }
            }
        }
        return -1;
    }
}
