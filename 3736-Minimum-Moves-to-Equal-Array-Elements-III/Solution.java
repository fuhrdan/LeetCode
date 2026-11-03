class Solution
{
    public int minMoves(int[] nums)
    {
        int maxValue = nums[0];
        int sum = 0;

        for (int value : nums)
        {
            maxValue = Math.max(maxValue, value);
            sum += value;
        }

        return maxValue * nums.length - sum;
    }
}
