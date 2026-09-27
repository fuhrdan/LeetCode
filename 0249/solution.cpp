#include <vector>
#include <string>
#include <unordered_map>
using namespace std;class Solution{string k(string&s){string r;for(char c:s)r+=char('a'+(c-s[0]+26)%26);return r;}public:vector<vector<string>> groupStrings(vector<string>&s){unordered_map<string,vector<string>>m;for(auto&x:s)m[k(x)].push_back(x);vector<vector<string>>o;for(auto&kv:m)o.push_back(kv.second);return o;}};
