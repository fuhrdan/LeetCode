#include <vector>
#include <climits>
#include <algorithm>
using namespace std;class Solution{public:int minPathSum(vector<vector<int>>&g){int n=g[0].size();vector<int>d(n,INT_MAX);d[0]=0;for(auto&r:g)for(int j=0;j<n;j++)d[j]=min(d[j],j?d[j-1]:INT_MAX)+r[j];return d.back();}};
