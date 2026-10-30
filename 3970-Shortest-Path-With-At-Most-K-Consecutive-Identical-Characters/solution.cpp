class Solution
{
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k)
    {
        auto& mavorqeli = edges;
        vector<vector<pair<int,int>>> graph(n);
        for (const auto& e : mavorqeli) graph[e[0]].push_back({e[1], e[2]});

        const long long INF = LLONG_MAX / 4;
        int spn = k + 1;
        vector<long long> dist((long long)n * spn, INF);
        auto idx = [spn](int u, int run){ return (long long)u * spn + run; };

        using State = tuple<long long,int,int>;
        priority_queue<State, vector<State>, greater<State>> pq;
        dist[idx(0,1)] = 0;
        pq.push({0,0,1});

        while (!pq.empty())
        {
            auto [d,u,run] = pq.top(); pq.pop();
            if (d != dist[idx(u,run)]) continue;
            if (u == n - 1) return (int)d;

            for (auto [v,w] : graph[u])
            {
                int nextRun = labels[u] == labels[v] ? run + 1 : 1;
                if (nextRun > k) continue;
                long long nd = d + w;
                long long id = idx(v,nextRun);
                if (nd < dist[id])
                {
                    dist[id] = nd;
                    pq.push({nd,v,nextRun});
                }
            }
        }
        return -1;
    }
};
