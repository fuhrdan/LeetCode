class Solution
{
public:
    int uniquePaths(vector<vector<int>>& grid)
    {
        static constexpr int MOD = 1000000007;

        int rows = static_cast<int>(grid.size());
        int cols = static_cast<int>(grid[0].size());

        vector<long long> down(cols, 0);
        down[0] = 1;

        long long left = 0;

        for (int row = 0; row < rows; row++)
        {
            left = 0;

            for (int col = 0; col < cols; col++)
            {
                if (grid[row][col] == 1)
                {
                    swap(left, down[col]);
                }
                else
                {
                    long long total =
                        (left + down[col]) % MOD;

                    left = total;
                    down[col] = total;
                }
            }
        }

        return static_cast<int>(left);
    }
};
