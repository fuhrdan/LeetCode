#include <string>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int maxDepth(string s)
    {
        int depth = 0;
        int retVal = 0;

        for (char c : s)
        {
            if (c == '(')
            {
                depth++;
                retVal = max(retVal, depth);
            }
            else if (c == ')')
            {
                depth--;
            }
        }

        return retVal;
    }
};
