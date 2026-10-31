impl Solution
{
    pub fn unique_paths(grid: Vec<Vec<i32>>) -> i32
    {
        const MOD: i64 = 1_000_000_007;

        let rows = grid.len();
        let cols = grid[0].len();

        let mut down = vec![0_i64; cols];
        down[0] = 1;

        let mut left = 0_i64;

        for row in 0..rows
        {
            left = 0;

            for col in 0..cols
            {
                if grid[row][col] == 1
                {
                    std::mem::swap(
                        &mut left,
                        &mut down[col]);
                }
                else
                {
                    let total =
                        (left + down[col]) % MOD;

                    left = total;
                    down[col] = total;
                }
            }
        }

        left as i32
    }
}
