import java.util.*;

class Solution
{
    public String largestNumber(int[] nums)
    {
        String[] values = new String[nums.length];

        for (int i = 0; i < nums.length; i++)
        {
            values[i] = Integer.toString(nums[i]);
        }

        Arrays.sort(values, (a, b) -> (b + a).compareTo(a + b));

        if (values[0].equals("0"))
        {
            return "0";
        }

        StringBuilder retVal = new StringBuilder();

        for (String value : values)
        {
            retVal.append(value);
        }

        return retVal.toString();
    }
}
