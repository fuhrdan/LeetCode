class Solution
{
    private int digitSum(int value)
    {
        int retVal = 0;

        while (value > 0)
        {
            retVal += value % 10;
            value /= 10;
        }

        return retVal;
    }

    public int minSwaps(int[] nums)
    {
        int n = nums.length;
        int[][] items = new int[n][3];

        for (int i = 0; i < n; i++)
        {
            items[i][0] = nums[i];
            items[i][1] = digitSum(nums[i]);
            items[i][2] = i;
        }

        java.util.Arrays.sort(items, (a, b) ->
        {
            if (a[1] != b[1])
            {
                return Integer.compare(a[1], b[1]);
            }

            return Integer.compare(a[0], b[0]);
        });

        int[] target = new int[n];

        for (int i = 0; i < n; i++)
        {
            target[items[i][2]] = i;
        }

        boolean[] visited = new boolean[n];
        int retVal = 0;

        for (int i = 0; i < n; i++)
        {
            if (visited[i] || target[i] == i)
            {
                continue;
            }

            int current = i;
            int cycleLength = 0;

            while (!visited[current])
            {
                visited[current] = true;
                current = target[current];
                cycleLength++;
            }

            retVal += cycleLength - 1;
        }

        return retVal;
    }
}
