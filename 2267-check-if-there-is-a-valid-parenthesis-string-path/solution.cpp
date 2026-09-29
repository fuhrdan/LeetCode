#include <vector>

using namespace std;

class Solution
{
public:
    bool hasValidPath(vector<vector<char>>& grid)
    {
        int rows = grid.size();
        int cols = grid[0].size();
        int pathLen = rows + cols - 1;

        if (grid[0][0] != '(' ||
            grid[rows - 1][cols - 1] != ')' ||
            (pathLen % 2) != 0)
        {
            return false;
        }

        vector<vector<char>> dp(cols, vector<char>(pathLen + 1, 0));
        dp[0][1] = 1;

        for (int r = 0; r < rows; r++)
        {
            for (int c = 0; c < cols; c++)
            {
                if (r == 0 && c == 0)
                {
                    continue;
                }

                vector<char> next(pathLen + 1, 0);
                int delta = grid[r][c] == '(' ? 1 : -1;

                if (r > 0)
                {
                    for (int balance = 0; balance <= pathLen; balance++)
                    {
                        if (dp[c][balance])
                        {
                            int newBalance = balance + delta;

                            if (newBalance >= 0 && newBalance <= pathLen)
                            {
                                next[newBalance] = 1;
                            }
                        }
                    }
                }

                if (c > 0)
                {
                    for (int balance = 0; balance <= pathLen; balance++)
                    {
                        if (dp[c - 1][balance])
                        {
                            int newBalance = balance + delta;

                            if (newBalance >= 0 && newBalance <= pathLen)
                            {
                                next[newBalance] = 1;
                            }
                        }
                    }
                }

                dp[c] = std::move(next);
            }
        }

        return dp[cols - 1][0];
    }
};
