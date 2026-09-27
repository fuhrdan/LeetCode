#include <vector>
#include <queue>
using namespace std;class Solution{public:vector<int> findOrder(int n,vector<vector<int>>&p){vector<vector<int>>g(n);vector<int>d(n),o;for(auto&e:p){g[e[1]].push_back(e[0]);d[e[0]]++;}queue<int>q;for(int i=0;i<n;i++)if(!d[i])q.push(i);while(!q.empty()){int u=q.front();q.pop();o.push_back(u);for(int v:g[u])if(--d[v]==0)q.push(v);}return o.size()==n?o:vector<int>{};}};
