impl Solution
{
    pub fn has_valid_path(grid: Vec<Vec<char>>) -> bool
    {
        let rows = grid.len();
        let cols = grid[0].len();
        let path_len = rows + cols - 1;

        if grid[0][0] != '('
            || grid[rows - 1][cols - 1] != ')'
            || path_len % 2 != 0
        {
            return false;
        }

        let mut dp = vec![vec![false; path_len + 1]; cols];
        dp[0][1] = true;

        for r in 0..rows
        {
            for c in 0..cols
            {
                if r == 0 && c == 0
                {
                    continue;
                }

                let mut next = vec![false; path_len + 1];
                let delta: i32 = if grid[r][c] == '(' { 1 } else { -1 };

                if r > 0
                {
                    for balance in 0..=path_len
                    {
                        if dp[c][balance]
                        {
                            let new_balance = balance as i32 + delta;

                            if new_balance >= 0 && new_balance <= path_len as i32
                            {
                                next[new_balance as usize] = true;
                            }
                        }
                    }
                }

                if c > 0
                {
                    for balance in 0..=path_len
                    {
                        if dp[c - 1][balance]
                        {
                            let new_balance = balance as i32 + delta;

                            if new_balance >= 0 && new_balance <= path_len as i32
                            {
                                next[new_balance as usize] = true;
                            }
                        }
                    }
                }

                dp[c] = next;
            }
        }

        dp[cols - 1][0]
    }
}
