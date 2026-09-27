#include <vector>
#include <queue>
using namespace std;class Solution{public:void wallsAndGates(vector<vector<int>>&r){if(r.empty())return;queue<pair<int,int>>q;for(int i=0;i<r.size();i++)for(int j=0;j<r[0].size();j++)if(r[i][j]==0)q.push({i,j});int d[5]={1,0,-1,0,1};while(!q.empty()){auto[x,y]=q.front();q.pop();for(int k=0;k<4;k++){int a=x+d[k],b=y+d[k+1];if(a>=0&&b>=0&&a<r.size()&&b<r[0].size()&&r[a][b]==INT_MAX){r[a][b]=r[x][y]+1;q.push({a,b});}}}}};
