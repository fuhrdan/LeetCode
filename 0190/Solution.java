public class Solution
{
    public int reverseBits(int n)
    {
        int retVal = 0;

        for (int i = 0; i < 32; i++)
        {
            retVal = (retVal << 1) | (n & 1);
            n >>>= 1;
        }

        return retVal;
    }
}
