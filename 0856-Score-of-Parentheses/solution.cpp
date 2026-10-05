class Solution
{
public:
    int scoreOfParentheses(string s)
    {
        int depth = 0;
        int score = 0;

        for (int i = 0; i < static_cast<int>(s.size()); i++)
        {
            if (s[i] == '(')
            {
                depth++;
            }
            else
            {
                depth--;

                if (i > 0 && s[i - 1] == '(')
                {
                    score += 1 << depth;
                }
            }
        }

        return score;
    }
};
