class Solution
{
public:
    vector<int> countServers(
        int n,
        vector<vector<int>>& logs,
        int x,
        vector<int>& queries)
    {
        sort(logs.begin(), logs.end(),
            [](const vector<int>& a, const vector<int>& b)
            {
                return a[1] < b[1];
            });

        vector<pair<int, int>> sortedQueries;

        for (int i = 0; i < static_cast<int>(queries.size()); i++)
        {
            sortedQueries.push_back({queries[i], i});
        }

        sort(sortedQueries.begin(), sortedQueries.end());

        vector<int> frequency(n + 1, 0);
        vector<int> answer(queries.size());

        int left = 0;
        int right = 0;
        int activeServers = 0;

        for (auto [currentTime, index] : sortedQueries)
        {
            while (right < static_cast<int>(logs.size())
                && logs[right][1] <= currentTime)
            {
                int server = logs[right][0];

                if (frequency[server] == 0)
                {
                    activeServers++;
                }

                frequency[server]++;
                right++;
            }

            int minimumTime = currentTime - x;

            while (left < right && logs[left][1] < minimumTime)
            {
                int server = logs[left][0];

                frequency[server]--;

                if (frequency[server] == 0)
                {
                    activeServers--;
                }

                left++;
            }

            answer[index] = n - activeServers;
        }

        return answer;
    }
};
