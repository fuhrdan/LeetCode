public class Solution
{
    public int[] MaxDepthAfterSplit(string seq)
    {
        int[] retVal = new int[seq.Length];
        int depth = 0;

        for (int i = 0; i < seq.Length; i++)
        {
            if (seq[i] == '(')
            {
                retVal[i] = depth & 1;
                depth++;
            }
            else
            {
                depth--;
                retVal[i] = depth & 1;
            }
        }

        return retVal;
    }
}
