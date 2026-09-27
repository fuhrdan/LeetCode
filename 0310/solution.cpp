#include <vector>
#include <queue>
using namespace std;class Solution{public:vector<int> findMinHeightTrees(int n,vector<vector<int>>&e){if(n==1)return{0};vector<vector<int>>g(n);vector<int>d(n);for(auto&x:e){g[x[0]].push_back(x[1]);g[x[1]].push_back(x[0]);d[x[0]]++;d[x[1]]++;}queue<int>q;for(int i=0;i<n;i++)if(d[i]==1)q.push(i);int left=n;while(left>2){int z=q.size();left-=z;while(z--){int u=q.front();q.pop();for(int v:g[u])if(--d[v]==1)q.push(v);}}vector<int>o;while(!q.empty()){o.push_back(q.front());q.pop();}return o;}};
