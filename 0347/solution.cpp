#include <vector>
#include <unordered_map>
using namespace std;class Solution{public:vector<int> topKFrequent(vector<int>&a,int k){unordered_map<int,int>m;for(int x:a)m[x]++;vector<vector<int>>b(a.size()+1);for(auto&[x,c]:m)b[c].push_back(x);vector<int>o;for(int i=b.size()-1;i>=0&&o.size()<k;i--)for(int x:b[i]){o.push_back(x);if(o.size()==k)break;}return o;}};
