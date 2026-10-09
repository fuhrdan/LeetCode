class Solution
{
    public int minInsertions(String s)
    {
        int insertions = 0;
        int needed = 0;

        for (int i = 0; i < s.length(); i++)
        {
            char ch = s.charAt(i);

            if (ch == '(')
            {
                if (needed % 2 == 1)
                {
                    insertions++;
                    needed--;
                }

                needed += 2;
            }
            else
            {
                needed--;

                if (needed < 0)
                {
                    insertions++;
                    needed = 1;
                }
            }
        }

        return insertions + needed;
    }
}
