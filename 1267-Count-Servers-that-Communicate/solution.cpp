class Solution
{
public:
    int countServers(vector<vector<int>>& grid)
    {
        int rows = static_cast<int>(grid.size());
        int cols = static_cast<int>(grid[0].size());

        vector<int> rowCount(rows, 0);
        vector<int> colCount(cols, 0);

        for (int row = 0; row < rows; row++)
        {
            for (int col = 0; col < cols; col++)
            {
                if (grid[row][col] == 1)
                {
                    rowCount[row]++;
                    colCount[col]++;
                }
            }
        }

        int retVal = 0;

        for (int row = 0; row < rows; row++)
        {
            for (int col = 0; col < cols; col++)
            {
                if (grid[row][col] == 1
                    && (rowCount[row] > 1 || colCount[col] > 1))
                {
                    retVal++;
                }
            }
        }

        return retVal;
    }
};
