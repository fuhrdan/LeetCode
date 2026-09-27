#include <vector>
using namespace std;class Solution{vector<vector<int>>o;void f(int k,int n,int st,vector<int>&v){if(v.size()==k){if(n==0)o.push_back(v);return;}for(int x=st;x<=9&&x<=n;x++){v.push_back(x);f(k,n-x,x+1,v);v.pop_back();}}public:vector<vector<int>> combinationSum3(int k,int n){vector<int>v;f(k,n,1,v);return o;}};
