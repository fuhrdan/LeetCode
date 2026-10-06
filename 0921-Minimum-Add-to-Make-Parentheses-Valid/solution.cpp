class Solution
{
public:
    int minAddToMakeValid(string s)
    {
        int balance = 0;
        int needed = 0;

        for (char ch : s)
        {
            if (ch == '(')
            {
                balance++;
            }
            else
            {
                if (balance > 0)
                {
                    balance--;
                }
                else
                {
                    needed++;
                }
            }
        }

        return needed + balance;
    }
};
