using System;

public class Solution
{
    public int Rob(int[] nums)
    {
        int prev2 = 0;
        int prev1 = 0;

        foreach (int x in nums)
        {
            int current = Math.Max(prev1, prev2 + x);
            prev2 = prev1;
            prev1 = current;
        }

        return prev1;
    }
}
