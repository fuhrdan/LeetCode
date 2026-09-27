#include <vector>
#include <queue>
#include <climits>
using namespace std;class Solution{public:int shortestDistance(vector<vector<int>>&g){int m=g.size(),n=g[0].size(),bc=0;vector<vector<int>>sum(m,vector<int>(n)),reach(m,vector<int>(n));int d[5]={1,0,-1,0,1};for(int i=0;i<m;i++)for(int j=0;j<n;j++)if(g[i][j]==1){bc++;queue<pair<int,int>>q;q.push({i,j});vector<vector<int>>v(m,vector<int>(n));int dist=0;while(!q.empty()){int z=q.size();dist++;while(z--){auto[x,y]=q.front();q.pop();for(int k=0;k<4;k++){int a=x+d[k],b=y+d[k+1];if(a>=0&&b>=0&&a<m&&b<n&&!v[a][b]&&g[a][b]==0){v[a][b]=1;sum[a][b]+=dist;reach[a][b]++;q.push({a,b});}}}}}int ans=INT_MAX;for(int i=0;i<m;i++)for(int j=0;j<n;j++)if(g[i][j]==0&&reach[i][j]==bc)ans=min(ans,sum[i][j]);return ans==INT_MAX?-1:ans;}};
