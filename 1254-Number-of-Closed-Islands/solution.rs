impl Solution
{
    fn fill(g: &mut Vec<Vec<i32>>, sr: usize, sc: usize)
    {
        let r = g.len();
        let c = g[0].len();
        let mut st = vec![(sr, sc)];
        g[sr][sc] = 1;
        let d = [(-1isize,0isize),(1,0),(0,-1),(0,1)];

        while let Some((x,y)) = st.pop()
        {
            for &(dx,dy) in &d
            {
                let nx = x as isize + dx;
                let ny = y as isize + dy;

                if nx < 0 || nx >= r as isize || ny < 0 || ny >= c as isize
                {
                    continue;
                }

                let nx = nx as usize;
                let ny = ny as usize;

                if g[nx][ny] != 0
                {
                    continue;
                }

                g[nx][ny] = 1;
                st.push((nx,ny));
            }
        }
    }

    pub fn closed_island(mut grid: Vec<Vec<i32>>) -> i32
    {
        let r = grid.len();
        let c = grid[0].len();

        for i in 0..r
        {
            if grid[i][0] == 0 { Self::fill(&mut grid, i, 0); }
            if grid[i][c - 1] == 0 { Self::fill(&mut grid, i, c - 1); }
        }

        for j in 0..c
        {
            if grid[0][j] == 0 { Self::fill(&mut grid, 0, j); }
            if grid[r - 1][j] == 0 { Self::fill(&mut grid, r - 1, j); }
        }

        let mut ret_val = 0;

        for i in 1..r.saturating_sub(1)
        {
            for j in 1..c.saturating_sub(1)
            {
                if grid[i][j] == 0
                {
                    ret_val += 1;
                    Self::fill(&mut grid, i, j);
                }
            }
        }

        ret_val
    }
}
