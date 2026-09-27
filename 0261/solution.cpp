#include <vector>
using namespace std;class Solution{void f(int u,vector<vector<int>>&g,vector<int>&v){v[u]=1;for(int x:g[u])if(!v[x])f(x,g,v);}public:bool validTree(int n,vector<vector<int>>&e){if(e.size()!=n-1)return false;vector<vector<int>>g(n);for(auto&x:e){g[x[0]].push_back(x[1]);g[x[1]].push_back(x[0]);}vector<int>v(n);f(0,g,v);for(int x:v)if(!x)return false;return true;}};
