impl Solution
{
    pub fn count_servers(grid: Vec<Vec<i32>>) -> i32
    {
        let rows = grid.len();
        let cols = grid[0].len();

        let mut row_count = vec![0_i32; rows];
        let mut col_count = vec![0_i32; cols];

        for row in 0..rows
        {
            for col in 0..cols
            {
                if grid[row][col] == 1
                {
                    row_count[row] += 1;
                    col_count[col] += 1;
                }
            }
        }

        let mut ret_val = 0_i32;

        for row in 0..rows
        {
            for col in 0..cols
            {
                if grid[row][col] == 1
                    && (row_count[row] > 1 || col_count[col] > 1)
                {
                    ret_val += 1;
                }
            }
        }

        ret_val
    }
}
