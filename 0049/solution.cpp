#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;class Solution{public:vector<vector<string>> groupAnagrams(vector<string>&s){unordered_map<string,vector<string>>m;for(auto x:s){string k=x;sort(k.begin(),k.end());m[k].push_back(x);}vector<vector<string>>o;for(auto&[k,v]:m)o.push_back(move(v));return o;}};
