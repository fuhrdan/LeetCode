impl Solution
{
    pub fn count_islands(mut grid: Vec<Vec<i32>>, k: i32) -> i32
    {
        let rows = grid.len();
        let cols = grid[0].len();

        let directions: [(isize, isize); 4] =
        [
            (-1, 0),
            (1, 0),
            (0, -1),
            (0, 1),
        ];

        let mut ret_val = 0_i32;

        for row in 0..rows
        {
            for col in 0..cols
            {
                if grid[row][col] <= 0
                {
                    continue;
                }

                let mut island_sum: i64 = grid[row][col] as i64;
                grid[row][col] = 0;

                let mut stack: Vec<(usize, usize)> = vec![(row, col)];

                while let Some((current_row, current_col)) = stack.pop()
                {
                    for &(dr, dc) in &directions
                    {
                        let next_row = current_row as isize + dr;
                        let next_col = current_col as isize + dc;

                        if next_row < 0
                            || next_row >= rows as isize
                            || next_col < 0
                            || next_col >= cols as isize
                        {
                            continue;
                        }

                        let nr = next_row as usize;
                        let nc = next_col as usize;

                        if grid[nr][nc] <= 0
                        {
                            continue;
                        }

                        island_sum += grid[nr][nc] as i64;
                        grid[nr][nc] = 0;
                        stack.push((nr, nc));
                    }
                }

                if island_sum % k as i64 == 0
                {
                    ret_val += 1;
                }
            }
        }

        ret_val
    }
}
