#include <vector>
using namespace std;class Solution{vector<vector<int>>o;void f(vector<int>&a,int st,int r,vector<int>&v){if(!r){o.push_back(v);return;}for(int i=st;i<a.size();i++)if(a[i]<=r){v.push_back(a[i]);f(a,i,r-a[i],v);v.pop_back();}}public:vector<vector<int>> combinationSum(vector<int>&a,int t){vector<int>v;f(a,0,t,v);return o;}};
