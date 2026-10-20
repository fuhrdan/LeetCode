class Solution
{
    private boolean check(int[] nums, int k)
    {
        int n = nums.length;
        boolean hasPrevious = false;
        int previousMax = 0;

        for (int start = 0; start < n; start += k)
        {
            int end = start + k;
            int blockMin = nums[start];
            int blockMax = nums[start];
            int descents = 0;

            for (int i = start; i < end; i++)
            {
                int next = (i + 1 < end) ? nums[i + 1] : nums[start];

                if (nums[i] > next)
                {
                    descents++;
                }

                blockMin = Math.min(blockMin, nums[i]);
                blockMax = Math.max(blockMax, nums[i]);

                if (descents > 1)
                {
                    return false;
                }
            }

            if (hasPrevious && previousMax > blockMin)
            {
                return false;
            }

            previousMax = blockMax;
            hasPrevious = true;
        }

        return true;
    }

    public int sortableIntegers(int[] nums)
    {
        int n = nums.length;
        int retVal = 0;

        for (int d = 1; (long)d * d <= n; d++)
        {
            if (n % d != 0)
            {
                continue;
            }

            if (check(nums, d))
            {
                retVal += d;
            }

            int other = n / d;

            if (other != d && check(nums, other))
            {
                retVal += other;
            }
        }

        return retVal;
    }
}
