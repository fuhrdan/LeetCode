class Solution
{
    public int minMoves(int[] nums)
    {
        int minValue = Integer.MAX_VALUE;

        for (int value : nums)
        {
            minValue = Math.min(minValue, value);
        }

        long moves = 0;

        for (int value : nums)
        {
            moves += (long)value - minValue;
        }

        return (int)moves;
    }
}
