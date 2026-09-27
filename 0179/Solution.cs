using System;
using System.Linq;

public class Solution
{
    public string LargestNumber(int[] nums)
    {
        string[] values = nums.Select(x => x.ToString()).ToArray();

        Array.Sort(values, (a, b) =>
            string.Compare(b + a, a + b, StringComparison.Ordinal));

        if (values[0] == "0")
        {
            return "0";
        }

        return string.Concat(values);
    }
}
