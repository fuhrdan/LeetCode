class Solution
{
    public int minMoves2(int[] nums)
    {
        java.util.Arrays.sort(nums);

        int median = nums[nums.length / 2];
        long moves = 0;

        for (int value : nums)
        {
            moves += Math.abs((long)value - median);
        }

        return (int)moves;
    }
}
