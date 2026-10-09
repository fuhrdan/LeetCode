class Solution
{
public:
    int minInsertions(string s)
    {
        int insertions = 0;
        int needed = 0;

        for (char ch : s)
        {
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
};
