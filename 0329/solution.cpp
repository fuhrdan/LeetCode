#include <vector>
#include <algorithm>
using namespace std;class Solution{int m,n;int f(vector<vector<int>>&a,int r,int c,vector<vector<int>>&dp){if(dp[r][c])return dp[r][c];int d[5]={1,0,-1,0,1};dp[r][c]=1;for(int k=0;k<4;k++){int x=r+d[k],y=c+d[k+1];if(x>=0&&y>=0&&x<m&&y<n&&a[x][y]>a[r][c])dp[r][c]=max(dp[r][c],1+f(a,x,y,dp));}return dp[r][c];}public:int longestIncreasingPath(vector<vector<int>>&a){if(a.empty())return 0;m=a.size();n=a[0].size();vector<vector<int>>dp(m,vector<int>(n));int b=0;for(int i=0;i<m;i++)for(int j=0;j<n;j++)b=max(b,f(a,i,j,dp));return b;}};
