class Solution
{
    private boolean check(int[] nums, int zero, int step)
    {
        int n = nums.length;
        for (int i = 1; i < n; i++)
        {
            int previous = (zero + (i - 1) * step) % n;
            int current = (zero + i * step) % n;
            if (previous < 0) previous += n;
            if (current < 0) current += n;
            if (nums[previous] > nums[current]) return false;
        }
        return true;
    }

    public int minOperations(int[] nums)
    {
        int n = nums.length;
        int zero = 0;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] == 0)
            {
                zero = i;
                break;
            }
        }

        int retVal = Integer.MAX_VALUE;
        if (check(nums, zero, 1))
        {
            retVal = Math.min(retVal, zero);
            retVal = Math.min(retVal, n - zero + 2);
        }
        if (check(nums, zero, -1))
        {
            retVal = Math.min(retVal, zero + 2);
            retVal = Math.min(retVal, n - zero);
        }
        return retVal == Integer.MAX_VALUE ? -1 : retVal;
    }
}
