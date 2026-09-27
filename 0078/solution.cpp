#include <vector>
using namespace std;class Solution{vector<vector<int>>o;void f(vector<int>&a,int i,vector<int>&v){if(i==a.size()){o.push_back(v);return;}f(a,i+1,v);v.push_back(a[i]);f(a,i+1,v);v.pop_back();}public:vector<vector<int>> subsets(vector<int>&a){vector<int>v;f(a,0,v);return o;}};
