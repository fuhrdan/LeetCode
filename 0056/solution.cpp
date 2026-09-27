#include <vector>
#include <algorithm>
using namespace std;class Solution{public:vector<vector<int>> merge(vector<vector<int>>&v){sort(v.begin(),v.end());vector<vector<int>>o;for(auto&x:v){if(o.empty()||x[0]>o.back()[1])o.push_back(x);else o.back()[1]=max(o.back()[1],x[1]);}return o;}};
