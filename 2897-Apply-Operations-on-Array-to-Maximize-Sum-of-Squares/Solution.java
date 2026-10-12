class Solution
{
    public int maxSum(java.util.List<Integer> nums, int k)
    {
        final long MOD = 1_000_000_007L;
        final int BITS = 31;

        int[] bitCount = new int[BITS];

        for (int value : nums)
        {
            for (int bit = 0; bit < BITS; bit++)
            {
                if (((value >> bit) & 1) != 0)
                {
                    bitCount[bit]++;
                }
            }
        }

        long retVal = 0;

        for (int i = 0; i < k; i++)
        {
            long value = 0;

            for (int bit = 0; bit < BITS; bit++)
            {
                if (bitCount[bit] > 0)
                {
                    value |= 1L << bit;
                    bitCount[bit]--;
                }
            }

            long modValue = value % MOD;
            retVal = (retVal + (modValue * modValue) % MOD) % MOD;
        }

        return (int)retVal;
    }
}
