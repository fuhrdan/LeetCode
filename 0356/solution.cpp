#include <vector>
#include <unordered_set>
#include <string>
#include <climits>
using namespace std;class Solution{public:bool isReflected(vector<vector<int>>&p){int lo=INT_MAX,hi=INT_MIN;unordered_set<string>s;for(auto&x:p){lo=min(lo,x[0]);hi=max(hi,x[0]);s.insert(to_string(x[0])+","+to_string(x[1]));}long long sum=(long long)lo+hi;for(auto&x:p)if(!s.count(to_string(sum-x[0])+","+to_string(x[1])))return false;return true;}};
