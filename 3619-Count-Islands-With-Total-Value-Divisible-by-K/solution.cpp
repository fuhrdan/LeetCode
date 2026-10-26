class Solution
{
public:
    int countIslands(vector<vector<int>>& grid, int k)
    {
        int rows = static_cast<int>(grid.size());
        int cols = static_cast<int>(grid[0].size());

        static const int directions[4][2] =
        {
            {-1, 0},
            {1, 0},
            {0, -1},
            {0, 1}
        };

        int retVal = 0;

        for (int row = 0; row < rows; row++)
        {
            for (int col = 0; col < cols; col++)
            {
                if (grid[row][col] <= 0)
                {
                    continue;
                }

                long long islandSum = 0;
                vector<pair<int, int>> stack;

                islandSum += grid[row][col];
                grid[row][col] = 0;
                stack.push_back({row, col});

                while (!stack.empty())
                {
                    auto [currentRow, currentCol] = stack.back();
                    stack.pop_back();

                    for (const auto& direction : directions)
                    {
                        int nextRow = currentRow + direction[0];
                        int nextCol = currentCol + direction[1];

                        if (nextRow < 0
                            || nextRow >= rows
                            || nextCol < 0
                            || nextCol >= cols
                            || grid[nextRow][nextCol] <= 0)
                        {
                            continue;
                        }

                        islandSum += grid[nextRow][nextCol];
                        grid[nextRow][nextCol] = 0;
                        stack.push_back({nextRow, nextCol});
                    }
                }

                if (islandSum % k == 0)
                {
                    retVal++;
                }
            }
        }

        return retVal;
    }
};
