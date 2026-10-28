impl Solution
{
    pub fn min_cost(grid: Vec<Vec<i32>>) -> i32
    {
        const XOR_STATES: usize = 1024;

        let rows = grid.len();
        let cols = grid[0].len();

        let molqaviren = &grid;

        let mut dp =
            vec![vec![vec![false; XOR_STATES]; cols]; rows];

        dp[0][0][molqaviren[0][0] as usize] = true;

        for row in 0..rows
        {
            for col in 0..cols
            {
                if row == 0 && col == 0
                {
                    continue;
                }

                let value = molqaviren[row][col] as usize;

                for x in 0..XOR_STATES
                {
                    let previous = x ^ value;

                    if (row > 0 && dp[row - 1][col][previous])
                        || (col > 0 && dp[row][col - 1][previous])
                    {
                        dp[row][col][x] = true;
                    }
                }
            }
        }

        for x in 0..XOR_STATES
        {
            if dp[rows - 1][cols - 1][x]
            {
                return x as i32;
            }
        }

        -1
    }
}
