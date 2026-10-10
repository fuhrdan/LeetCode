class Solution
{
    public long minSumSquareDiff(int[] nums1, int[] nums2, int k1, int k2)
    {
        final int MAX_DIFF = 100000;
        long[] count = new long[MAX_DIFF + 1];

        long totalDiff = 0;
        int maxDiff = 0;

        for (int i = 0; i < nums1.length; i++)
        {
            int diff = Math.abs(nums1[i] - nums2[i]);

            count[diff]++;
            totalDiff += diff;
            maxDiff = Math.max(maxDiff, diff);
        }

        long operations = (long)k1 + (long)k2;

        if (operations >= totalDiff)
        {
            return 0;
        }

        for (int diff = maxDiff; diff > 0 && operations > 0; diff--)
        {
            if (count[diff] == 0)
            {
                continue;
            }

            long moved = Math.min(count[diff], operations);

            count[diff] -= moved;
            count[diff - 1] += moved;
            operations -= moved;
        }

        long retVal = 0;

        for (int diff = 1; diff <= maxDiff; diff++)
        {
            retVal += count[diff] * (long)diff * (long)diff;
        }

        return retVal;
    }
}
