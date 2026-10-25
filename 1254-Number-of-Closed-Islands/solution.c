#include <stdlib.h>

static void fill(int** g, int r, int c, int sr, int sc)
{
    int cap = r * c;
    int* rs = malloc(sizeof(int) * cap);
    int* cs = malloc(sizeof(int) * cap);
    if (!rs || !cs)
    {
        free(rs);
        free(cs);
        return;
    }

    int top = 0;
    rs[top] = sr;
    cs[top] = sc;
    top++;
    g[sr][sc] = 1;

    int d[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};

    while (top > 0)
    {
        top--;
        int x = rs[top];
        int y = cs[top];

        for (int i = 0; i < 4; i++)
        {
            int nx = x + d[i][0];
            int ny = y + d[i][1];

            if (nx < 0 || nx >= r || ny < 0 || ny >= c || g[nx][ny] != 0)
            {
                continue;
            }

            g[nx][ny] = 1;
            rs[top] = nx;
            cs[top] = ny;
            top++;
        }
    }

    free(rs);
    free(cs);
}

int closedIsland(int** grid, int gridSize, int* gridColSize)
{
    int r = gridSize;
    int c = gridColSize[0];

    for (int i = 0; i < r; i++)
    {
        if (grid[i][0] == 0) fill(grid, r, c, i, 0);
        if (grid[i][c - 1] == 0) fill(grid, r, c, i, c - 1);
    }

    for (int j = 0; j < c; j++)
    {
        if (grid[0][j] == 0) fill(grid, r, c, 0, j);
        if (grid[r - 1][j] == 0) fill(grid, r, c, r - 1, j);
    }

    int retVal = 0;

    for (int i = 1; i < r - 1; i++)
    {
        for (int j = 1; j < c - 1; j++)
        {
            if (grid[i][j] == 0)
            {
                retVal++;
                fill(grid, r, c, i, j);
            }
        }
    }

    return retVal;
}
