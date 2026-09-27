#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    string largestNumber(vector<int>& nums)
    {
        vector<string> values;

        for (int x : nums)
        {
            values.push_back(to_string(x));
        }

        sort(values.begin(), values.end(),
            [](const string& a, const string& b)
            {
                return a + b > b + a;
            });

        if (values[0] == "0")
        {
            return "0";
        }

        string retVal;

        for (const string& value : values)
        {
            retVal += value;
        }

        return retVal;
    }
};
