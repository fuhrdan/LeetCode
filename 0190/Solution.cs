public class Solution
{
    public uint reverseBits(uint n)
    {
        uint retVal = 0;

        for (int i = 0; i < 32; i++)
        {
            retVal = (retVal << 1) | (n & 1U);
            n >>= 1;
        }

        return retVal;
    }
}
