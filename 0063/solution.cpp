#include <vector>
using namespace std;class Solution{public:int uniquePathsWithObstacles(vector<vector<int>>&g){int n=g[0].size();vector<int>d(n);d[0]=1;for(auto&r:g)for(int j=0;j<n;j++)if(r[j])d[j]=0;else if(j)d[j]+=d[j-1];return d.back();}};
