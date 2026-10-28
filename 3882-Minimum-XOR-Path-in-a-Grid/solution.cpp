class Solution
{
public:
    int minCost(vector<vector<int>>& grid)
    {
        static constexpr int XOR_STATES = 1024;

        int rows = static_cast<int>(grid.size());
        int cols = static_cast<int>(grid[0].size());

        auto& molqaviren = grid;

        vector<vector<vector<char>>> dp(
            rows,
            vector<vector<char>>(
                cols,
                vector<char>(XOR_STATES, 0)));

        dp[0][0][molqaviren[0][0]] = 1;

        for (int row = 0; row < rows; row++)
        {
            for (int col = 0; col < cols; col++)
            {
                if (row == 0 && col == 0)
                {
                    continue;
                }

                int value = molqaviren[row][col];

                for (int x = 0; x < XOR_STATES; x++)
                {
                    int previous = x ^ value;

                    if ((row > 0 && dp[row - 1][col][previous])
                        || (col > 0 && dp[row][col - 1][previous]))
                    {
                        dp[row][col][x] = 1;
                    }
                }
            }
        }

        for (int x = 0; x < XOR_STATES; x++)
        {
            if (dp[rows - 1][cols - 1][x])
            {
                return x;
            }
        }

        return -1;
    }
};
