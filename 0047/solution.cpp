#include <vector>
#include <algorithm>
using namespace std;class Solution{vector<vector<int>>o;void f(vector<int>&a,vector<int>&u,vector<int>&v){if(v.size()==a.size()){o.push_back(v);return;}for(int i=0;i<a.size();i++){if(u[i]||(i&&a[i]==a[i-1]&&!u[i-1]))continue;u[i]=1;v.push_back(a[i]);f(a,u,v);v.pop_back();u[i]=0;}}public:vector<vector<int>> permuteUnique(vector<int>&a){sort(a.begin(),a.end());vector<int>u(a.size()),v;f(a,u,v);return o;}};
