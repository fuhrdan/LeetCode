#include <vector>
#include <set>
#include <algorithm>
using namespace std;class Solution{public:vector<vector<int>> getSkyline(vector<vector<int>>&b){vector<pair<int,int>>e;for(auto&x:b){e.push_back({x[0],-x[2]});e.push_back({x[1],x[2]});}sort(e.begin(),e.end());multiset<int>h{0};vector<vector<int>>o;int prev=0;for(auto [x,v]:e){if(v<0)h.insert(-v);else h.erase(h.find(v));int cur=*h.rbegin();if(cur!=prev){o.push_back({x,cur});prev=cur;}}return o;}};
