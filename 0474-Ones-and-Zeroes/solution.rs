impl Solution
{
    pub fn find_max_form(strs: Vec<String>, m: i32, n: i32) -> i32
    {
        let m = m as usize;
        let n = n as usize;

        let mut dp = vec![vec![0_i32; n + 1]; m + 1];

        for s in strs
        {
            let mut zeroes = 0_usize;
            let mut ones = 0_usize;

            for ch in s.bytes()
            {
                if ch == b'0'
                {
                    zeroes += 1;
                }
                else
                {
                    ones += 1;
                }
            }

            for z in (zeroes..=m).rev()
            {
                for o in (ones..=n).rev()
                {
                    dp[z][o] = dp[z][o].max(
                        dp[z - zeroes][o - ones] + 1);
                }
            }
        }

        dp[m][n]
    }
}
