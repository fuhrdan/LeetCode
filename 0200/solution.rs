impl Solution
{
    pub fn num_islands(mut grid: Vec<Vec<char>>) -> i32
    {
        fn flood(grid: &mut Vec<Vec<char>>, r: i32, c: i32)
        {
            if r < 0 || c < 0 ||
               r >= grid.len() as i32 ||
               c >= grid[0].len() as i32 ||
               grid[r as usize][c as usize] != '1'
            {
                return;
            }

            grid[r as usize][c as usize] = '0';

            flood(grid, r + 1, c);
            flood(grid, r - 1, c);
            flood(grid, r, c + 1);
            flood(grid, r, c - 1);
        }

        let mut ret_val = 0;

        for r in 0..grid.len()
        {
            for c in 0..grid[0].len()
            {
                if grid[r][c] == '1'
                {
                    ret_val += 1;
                    flood(&mut grid, r as i32, c as i32);
                }
            }
        }

        ret_val
    }
}
