class Solution
{
public:
    int minOperations(string s)
    {
        int n = static_cast<int>(s.size());

        for (int i = 1; i < n; i++)
        {
            if (s[i] < s[i - 1])
            {
                goto notSorted;
            }
        }

        return 0;

    notSorted:
        if (n == 2)
        {
            return -1;
        }

        char mn = s[0];
        char mx = s[0];

        for (char ch : s)
        {
            mn = min(mn, ch);
            mx = max(mx, ch);
        }

        if (s[0] == mn || s[n - 1] == mx)
        {
            return 1;
        }

        for (int i = 1; i < n - 1; i++)
        {
            if (s[i] == mn || s[i] == mx)
            {
                return 2;
            }
        }

        return 3;
    }
};
