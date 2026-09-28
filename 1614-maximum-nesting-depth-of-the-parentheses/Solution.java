class Solution
{
    public int maxDepth(String s)
    {
        int depth = 0;
        int retVal = 0;

        for (char c : s.toCharArray())
        {
            if (c == '(')
            {
                depth++;
                retVal = Math.max(retVal, depth);
            }
            else if (c == ')')
            {
                depth--;
            }
        }

        return retVal;
    }
}
