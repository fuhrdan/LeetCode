class Solution
{
public:
    string removeOuterParentheses(string s)
    {
        string result;
        result.reserve(s.size());

        int depth = 0;

        for (char ch : s)
        {
            if (ch == '(')
            {
                if (depth > 0)
                {
                    result.push_back(ch);
                }

                depth++;
            }
            else
            {
                depth--;

                if (depth > 0)
                {
                    result.push_back(ch);
                }
            }
        }

        return result;
    }
};
