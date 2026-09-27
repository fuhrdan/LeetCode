public class Solution
{
    public int hammingWeight(int n)
    {
        int retVal = 0;

        while (n != 0)
        {
            n &= n - 1;
            retVal++;
        }

        return retVal;
    }
}
