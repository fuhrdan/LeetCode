#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int maxSelectedElements(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> dp(nums.back() + 2, 0);
        int answer = 0;
        for (int x : nums) {
            // Update x+1 first; otherwise this element could be counted twice.
            dp[x + 1] = max(dp[x + 1], dp[x] + 1);
            dp[x] = max(dp[x], dp[x - 1] + 1);
            answer = max({answer, dp[x], dp[x + 1]});
        }
        return answer;
    }
};
