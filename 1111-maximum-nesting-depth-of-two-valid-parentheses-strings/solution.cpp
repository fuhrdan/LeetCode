#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> maxDepthAfterSplit(string seq)
    {
        vector<int> retVal(seq.size());
        int depth = 0;

        for (int i = 0; i < static_cast<int>(seq.size()); i++)
        {
            if (seq[i] == '(')
            {
                retVal[i] = depth & 1;
                depth++;
            }
            else
            {
                depth--;
                retVal[i] = depth & 1;
            }
        }

        return retVal;
    }
};
