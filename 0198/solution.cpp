#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int rob(vector<int>& nums)
    {
        int prev2 = 0;
        int prev1 = 0;

        for (int x : nums)
        {
            int current = max(prev1, prev2 + x);
            prev2 = prev1;
            prev1 = current;
        }

        return prev1;
    }
};
