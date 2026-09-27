#include <vector>
using namespace std;class Solution{vector<vector<int>>o;void f(int n,int k,int st,vector<int>&v){if(v.size()==k){o.push_back(v);return;}for(int x=st;x<=n-(k-v.size())+1;x++){v.push_back(x);f(n,k,x+1,v);v.pop_back();}}public:vector<vector<int>> combine(int n,int k){vector<int>v;f(n,k,1,v);return o;}};
