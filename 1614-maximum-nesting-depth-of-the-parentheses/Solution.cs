public class Solution
{
    public int MaxDepth(string s)
    {
        int depth = 0;
        int retVal = 0;

        foreach (char c in s)
        {
            if (c == '(')
            {
                depth++;

                if (depth > retVal)
                {
                    retVal = depth;
                }
            }
            else if (c == ')')
            {
                depth--;
            }
        }

        return retVal;
    }
}
