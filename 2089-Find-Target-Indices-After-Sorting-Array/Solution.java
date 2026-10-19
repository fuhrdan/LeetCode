class Solution
{
    public java.util.List<Integer> targetIndices(int[] nums, int target)
    {
        int less = 0;
        int equal = 0;

        for (int value : nums)
        {
            if (value < target)
            {
                less++;
            }
            else if (value == target)
            {
                equal++;
            }
        }

        java.util.List<Integer> retVal =
            new java.util.ArrayList<>(equal);

        for (int i = 0; i < equal; i++)
        {
            retVal.add(less + i);
        }

        return retVal;
    }
}
