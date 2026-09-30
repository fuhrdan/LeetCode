class Solution
{
    public int[] maxDepthAfterSplit(String seq)
    {
        int[] retVal = new int[seq.length()];
        int depth = 0;

        for (int i = 0; i < seq.length(); i++)
        {
            if (seq.charAt(i) == '(')
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
