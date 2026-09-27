#include <vector>
using namespace std;class Solution{int f(vector<int>&p,int x){return p[x]==x?x:p[x]=f(p,p[x]);}public:int countComponents(int n,vector<vector<int>>&e){vector<int>p(n);for(int i=0;i<n;i++)p[i]=i;int c=n;for(auto&x:e){int a=f(p,x[0]),b=f(p,x[1]);if(a!=b){p[a]=b;c--;}}return c;}};
