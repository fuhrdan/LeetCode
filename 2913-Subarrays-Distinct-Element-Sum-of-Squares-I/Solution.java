class Solution
{
    public int sumCounts(java.util.List<Integer> nums)
    {
        int retVal = 0;

        for (int start = 0; start < nums.size(); start++)
        {
            boolean[] seen = new boolean[101];
            int distinct = 0;

            for (int end = start; end < nums.size(); end++)
            {
                int value = nums.get(end);

                if (!seen[value])
                {
                    seen[value] = true;
                    distinct++;
                }

                retVal += distinct * distinct;
            }
        }

        return retVal;
    }
}
