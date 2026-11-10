impl Solution
{
    pub fn climb_stairs(n: i32, costs: Vec<i32>) -> i32
    {
        let n = n as usize;
        let inf = i64::MAX / 4;

        let mut dp = [0_i64, inf, inf, inf];

        for step in 1..=n
        {
            let mut best = inf;

            for jump in 1..=3usize
            {
                if jump > step
                {
                    continue;
                }

                let previous = step - jump;

                let candidate =
                    dp[previous % 4]
                    + (jump * jump) as i64;

                best = best.min(candidate);
            }

            dp[step % 4] =
                best + costs[step - 1] as i64;
        }

        dp[n % 4] as i32
    }
}
