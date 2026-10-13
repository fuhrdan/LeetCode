class Solution
{
    public long maxAlternatingSum(int[] nums)
    {
        long[] squares = new long[nums.length];

        for (int i = 0; i < nums.length; i++)
        {
            long value = nums[i];
            squares[i] = value * value;
        }

        java.util.Arrays.sort(squares);

        int negativeCount = nums.length / 2;
        long retVal = 0;

        for (int i = 0; i < squares.length; i++)
        {
            if (i < negativeCount)
            {
                retVal -= squares[i];
            }
            else
            {
                retVal += squares[i];
            }
        }

        return retVal;
    }
}
