using System;
using System.Collections.Generic;

public class Solution
{
    private int KeyboardRow(char c)
    {
        c = char.ToLowerInvariant(c);

        if ("qwertyuiop".IndexOf(c) >= 0)
        {
            return 1;
        }

        if ("asdfghjkl".IndexOf(c) >= 0)
        {
            return 2;
        }

        return 3;
    }

    public string[] FindWords(string[] words)
    {
        List<string> retVal = new List<string>();

        foreach (string word in words)
        {
            if (string.IsNullOrEmpty(word))
            {
                continue;
            }

            int row = KeyboardRow(word[0]);
            bool valid = true;

            for (int i = 1; i < word.Length; i++)
            {
                if (KeyboardRow(word[i]) != row)
                {
                    valid = false;
                    break;
                }
            }

            if (valid)
            {
                retVal.Add(word);
            }
        }

        return retVal.ToArray();
    }
}
