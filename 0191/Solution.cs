public class Solution
{
    public int HammingWeight(uint n)
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
