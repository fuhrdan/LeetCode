class Solution
{
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks)
    {
        using Free = pair<int,int>;
        using Busy = tuple<long long,int,int>;

        priority_queue<Free, vector<Free>, greater<Free>> freeServers;
        priority_queue<Busy, vector<Busy>, greater<Busy>> busyServers;

        for (int i = 0; i < (int)servers.size(); i++)
            freeServers.push({servers[i], i});

        vector<int> ans(tasks.size());
        long long time = 0;

        for (int i = 0; i < (int)tasks.size(); i++)
        {
            time = max(time, (long long)i);

            while (!busyServers.empty() && get<0>(busyServers.top()) <= time)
            {
                auto [freeTime, weight, index] = busyServers.top();
                busyServers.pop();
                freeServers.push({weight, index});
            }

            if (freeServers.empty())
            {
                time = get<0>(busyServers.top());

                while (!busyServers.empty() && get<0>(busyServers.top()) <= time)
                {
                    auto [freeTime, weight, index] = busyServers.top();
                    busyServers.pop();
                    freeServers.push({weight, index});
                }
            }

            auto [weight, index] = freeServers.top();
            freeServers.pop();

            ans[i] = index;
            busyServers.push({time + tasks[i], weight, index});
        }

        return ans;
    }
};
