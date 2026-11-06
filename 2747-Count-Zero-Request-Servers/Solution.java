class Solution
{
    public int[] countServers(
        int n,
        int[][] logs,
        int x,
        int[] queries)
    {
        java.util.Arrays.sort(
            logs,
            (a, b) -> Integer.compare(a[1], b[1]));

        int[][] sortedQueries =
            new int[queries.length][2];

        for (int i = 0; i < queries.length; i++)
        {
            sortedQueries[i][0] = queries[i];
            sortedQueries[i][1] = i;
        }

        java.util.Arrays.sort(
            sortedQueries,
            (a, b) -> Integer.compare(a[0], b[0]));

        int[] frequency = new int[n + 1];
        int[] answer = new int[queries.length];

        int left = 0;
        int right = 0;
        int activeServers = 0;

        for (int[] query : sortedQueries)
        {
            int currentTime = query[0];
            int index = query[1];

            while (right < logs.length
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

            while (left < right
                && logs[left][1] < minimumTime)
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
}
