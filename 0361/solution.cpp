#include <vector>
#include <algorithm>
using namespace std;class Solution{public:int maxKilledEnemies(vector<vector<char>>&g){if(g.empty())return 0;int m=g.size(),n=g[0].size(),row=0,b=0;vector<int>c(n);for(int i=0;i<m;i++)for(int j=0;j<n;j++){if(j==0||g[i][j-1]=='W'){row=0;for(int k=j;k<n&&g[i][k]!='W';k++)row+=g[i][k]=='E';}if(i==0||g[i-1][j]=='W'){c[j]=0;for(int k=i;k<m&&g[k][j]!='W';k++)c[j]+=g[k][j]=='E';}if(g[i][j]=='0')b=max(b,row+c[j]);}return b;}};
