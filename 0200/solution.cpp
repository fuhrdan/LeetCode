#include <vector>
using namespace std;

class Solution
{
    void flood(vector<vector<char>>& grid, int r, int c)
    {
        if (r < 0 || c < 0 ||
            r >= grid.size() || c >= grid[0].size() ||
            grid[r][c] != '1')
        {
            return;
        }

        grid[r][c] = '0';

        flood(grid, r + 1, c);
        flood(grid, r - 1, c);
        flood(grid, r, c + 1);
        flood(grid, r, c - 1);
    }

public:
    int numIslands(vector<vector<char>>& grid)
    {
        int retVal = 0;

        for (int r = 0; r < grid.size(); r++)
        {
            for (int c = 0; c < grid[0].size(); c++)
            {
                if (grid[r][c] == '1')
                {
                    retVal++;
                    flood(grid, r, c);
                }
            }
        }

        return retVal;
    }
};
