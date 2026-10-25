class Solution
{
    void fill(vector<vector<int>>& g, int sr, int sc)
    {
        int r = g.size(), c = g[0].size();
        vector<pair<int,int>> st{{sr,sc}};
        g[sr][sc] = 1;
        int d[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};

        while (!st.empty())
        {
            auto [x,y] = st.back();
            st.pop_back();

            for (auto& v : d)
            {
                int nx = x + v[0], ny = y + v[1];
                if (nx < 0 || nx >= r || ny < 0 || ny >= c || g[nx][ny] != 0)
                    continue;

                g[nx][ny] = 1;
                st.push_back({nx,ny});
            }
        }
    }

public:
    int closedIsland(vector<vector<int>>& grid)
    {
        int r = grid.size(), c = grid[0].size();

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
};
