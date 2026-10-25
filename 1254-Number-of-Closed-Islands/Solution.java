class Solution
{
    private void fill(int[][] g, int sr, int sc)
    {
        int r = g.length, c = g[0].length;
        int[] rs = new int[r * c];
        int[] cs = new int[r * c];
        int top = 0;

        rs[top] = sr;
        cs[top] = sc;
        top++;
        g[sr][sc] = 1;

        int[][] d = {{-1,0},{1,0},{0,-1},{0,1}};

        while (top > 0)
        {
            top--;
            int x = rs[top], y = cs[top];

            for (int[] v : d)
            {
                int nx = x + v[0], ny = y + v[1];

                if (nx < 0 || nx >= r || ny < 0 || ny >= c || g[nx][ny] != 0)
                    continue;

                g[nx][ny] = 1;
                rs[top] = nx;
                cs[top] = ny;
                top++;
            }
        }
    }

    public int closedIsland(int[][] grid)
    {
        int r = grid.length, c = grid[0].length;

        for (int i = 0; i < r; i++)
        {
            if (grid[i][0] == 0) fill(grid, i, 0);
            if (grid[i][c - 1] == 0) fill(grid, i, c - 1);
        }

        for (int j = 0; j < c; j++)
        {
            if (grid[0][j] == 0) fill(grid, 0, j);
            if (grid[r - 1][j] == 0) fill(grid, r - 1, j);
        }

        int retVal = 0;

        for (int i = 1; i < r - 1; i++)
        {
            for (int j = 1; j < c - 1; j++)
            {
                if (grid[i][j] == 0)
                {
                    retVal++;
                    fill(grid, i, j);
                }
            }
        }

        return retVal;
    }
}
