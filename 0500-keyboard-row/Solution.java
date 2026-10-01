import java.util.ArrayList;
import java.util.List;

class Solution
{
    private int keyboardRow(char c)
    {
        c = Character.toLowerCase(c);

        if ("qwertyuiop".indexOf(c) >= 0)
        {
            return 1;
        }

        if ("asdfghjkl".indexOf(c) >= 0)
        {
            return 2;
        }

        return 3;
    }

    public String[] findWords(String[] words)
    {
        List<String> retVal = new ArrayList<>();

        for (String word : words)
        {
            if (word.isEmpty())
            {
                continue;
            }

            int row = keyboardRow(word.charAt(0));
            boolean valid = true;

            for (int i = 1; i < word.length(); i++)
            {
                if (keyboardRow(word.charAt(i)) != row)
                {
                    valid = false;
                    break;
                }
            }

            if (valid)
            {
                retVal.add(word);
            }
        }

        return retVal.toArray(new String[0]);
    }
}
