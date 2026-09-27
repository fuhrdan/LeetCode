#include <vector>
#include <climits>
#include <algorithm>
using namespace std;class Solution{public:int calculateMinimumHP(vector<vector<int>>&d){int n=d[0].size();vector<int>dp(n+1,INT_MAX/2);dp[n-1]=1;for(int i=d.size()-1;i>=0;i--)for(int j=n-1;j>=0;j--)dp[j]=max(1,min(dp[j],dp[j+1])-d[i][j]);return dp[0];}};
