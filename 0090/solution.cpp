#include <vector>
#include <algorithm>
using namespace std;class Solution{vector<vector<int>>o;void f(vector<int>&a,int st,vector<int>&v){o.push_back(v);for(int i=st;i<a.size();i++){if(i>st&&a[i]==a[i-1])continue;v.push_back(a[i]);f(a,i+1,v);v.pop_back();}}public:vector<vector<int>> subsetsWithDup(vector<int>&a){sort(a.begin(),a.end());vector<int>v;f(a,0,v);return o;}};
