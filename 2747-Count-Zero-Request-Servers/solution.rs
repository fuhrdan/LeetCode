impl Solution
{
    pub fn count_servers(
        n: i32,
        mut logs: Vec<Vec<i32>>,
        x: i32,
        queries: Vec<i32>) -> Vec<i32>
    {
        logs.sort_unstable_by_key(|entry| entry[1]);

        let mut sorted_queries: Vec<(i32, usize)> =
            queries.iter()
                .enumerate()
                .map(|(index, &time)| (time, index))
                .collect();

        sorted_queries.sort_unstable();

        let mut frequency = vec![0_i32; n as usize + 1];
        let mut answer = vec![0_i32; queries.len()];

        let mut left = 0usize;
        let mut right = 0usize;
        let mut active_servers = 0_i32;

        for (current_time, index) in sorted_queries
        {
            while right < logs.len() && logs[right][1] <= current_time
            {
                let server = logs[right][0] as usize;

                if frequency[server] == 0
                {
                    active_servers += 1;
                }

                frequency[server] += 1;
                right += 1;
            }

            let minimum_time = current_time - x;

            while left < right && logs[left][1] < minimum_time
            {
                let server = logs[left][0] as usize;

                frequency[server] -= 1;

                if frequency[server] == 0
                {
                    active_servers -= 1;
                }

                left += 1;
            }

            answer[index] = n - active_servers;
        }

        answer
    }
}
