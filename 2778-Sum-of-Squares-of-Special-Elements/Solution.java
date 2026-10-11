class Solution
{
    public int sumOfSquares(int[] nums)
    {
        int retVal = 0;
        int n = nums.length;

        for (int i = 0; i < n; i++)
        {
            int index = i + 1;

            if (n % index == 0)
            {
                retVal += nums[i] * nums[i];
            }
        }

        return retVal;
    }
}
