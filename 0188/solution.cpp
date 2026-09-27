#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution
{
public:
    int maxProfit(int k, vector<int>& prices)
    {
        int n = prices.size();

        if (k >= n / 2)
        {
            int retVal = 0;

            for (int i = 1; i < n; i++)
            {
                retVal += max(0, prices[i] - prices[i - 1]);
            }

            return retVal;
        }

        vector<int> buy(k + 1, INT_MIN / 2);
        vector<int> sell(k + 1, 0);

        for (int price : prices)
        {
            for (int t = 1; t <= k; t++)
            {
                buy[t] = max(buy[t], sell[t - 1] - price);
                sell[t] = max(sell[t], buy[t] + price);
            }
        }

        return sell[k];
    }
};
