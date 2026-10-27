class Solution
{
    public String[] createGrid(int m, int n)
    {
        String[] result = new String[m];

        for (int row = 0; row < m; row++)
        {
            char[] current = new char[n];
            java.util.Arrays.fill(current, '#');

            if (row == 0)
            {
                java.util.Arrays.fill(current, '.');
            }

            current[n - 1] = '.';

            result[row] = new String(current);
        }

        return result;
    }
}