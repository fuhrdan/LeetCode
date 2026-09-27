#include <string>
#include <vector>
using namespace std;class Solution{vector<vector<string>>o;bool p(string&s,int l,int r){while(l<r)if(s[l++]!=s[r--])return false;return true;}void f(string&s,int st,vector<string>&v){if(st==s.size()){o.push_back(v);return;}for(int e=st;e<s.size();e++)if(p(s,st,e)){v.push_back(s.substr(st,e-st+1));f(s,e+1,v);v.pop_back();}}public:vector<vector<string>> partition(string s){vector<string>v;f(s,0,v);return o;}};
