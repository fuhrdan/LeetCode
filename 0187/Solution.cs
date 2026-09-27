using System.Collections.Generic;

public class Solution
{
    public IList<string> FindRepeatedDnaSequences(string s)
    {
        var seen = new HashSet<string>();
        var repeated = new HashSet<string>();

        for (int i = 0; i + 10 <= s.Length; i++)
        {
            string seq = s.Substring(i, 10);

            if (!seen.Add(seq))
            {
                repeated.Add(seq);
            }
        }

        return new List<string>(repeated);
    }
}
