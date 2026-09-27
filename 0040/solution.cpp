#include <vector>
#include <algorithm>
using namespace std;class Solution{vector<vector<int>>o;void f(vector<int>&a,int st,int r,vector<int>&v){if(!r){o.push_back(v);return;}for(int i=st;i<a.size()&&a[i]<=r;i++){if(i>st&&a[i]==a[i-1])continue;v.push_back(a[i]);f(a,i+1,r-a[i],v);v.pop_back();}}public:vector<vector<int>> combinationSum2(vector<int>&a,int t){sort(a.begin(),a.end());vector<int>v;f(a,0,t,v);return o;}};
