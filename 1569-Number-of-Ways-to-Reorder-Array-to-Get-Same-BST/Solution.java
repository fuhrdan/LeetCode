class Solution
{
    private static final long MOD = 1_000_000_007L;
    private long[][] combinations;

    private long countWays(java.util.List<Integer> nums)
    {
        int n = nums.size();

        if (n <= 2)
        {
            return 1;
        }

        int root = nums.get(0);
        java.util.List<Integer> left = new java.util.ArrayList<>();
        java.util.List<Integer> right = new java.util.ArrayList<>();

        for (int i = 1; i < n; i++)
        {
            int value = nums.get(i);

            if (value < root)
            {
                left.add(value);
            }
            else
            {
                right.add(value);
            }
        }

        long retVal =
            combinations[left.size() + right.size()][left.size()];

        retVal = (retVal * countWays(left)) % MOD;
        retVal = (retVal * countWays(right)) % MOD;

        return retVal;
    }

    public int numOfWays(int[] nums)
    {
        int n = nums.length;

        combinations = new long[n + 1][n + 1];

        for (int i = 0; i <= n; i++)
        {
            combinations[i][0] = 1;
            combinations[i][i] = 1;

            for (int j = 1; j < i; j++)
            {
                combinations[i][j] =
                    (combinations[i - 1][j - 1]
                    + combinations[i - 1][j]) % MOD;
            }
        }

        java.util.List<Integer> values = new java.util.ArrayList<>(n);

        for (int value : nums)
        {
            values.add(value);
        }

        long totalWays = countWays(values);

        return (int)((totalWays - 1 + MOD) % MOD);
    }
}
