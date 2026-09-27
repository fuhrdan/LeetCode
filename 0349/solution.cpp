#include <vector>
#include <unordered_set>
using namespace std;class Solution{public:vector<int> intersection(vector<int>&a,vector<int>&b){unordered_set<int>s(a.begin(),a.end()),o;for(int x:b)if(s.count(x))o.insert(x);return vector<int>(o.begin(),o.end());}};
