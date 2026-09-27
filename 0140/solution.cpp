#include <string>
#include <vector>
#include <unordered_map>
using namespace std;class Solution{vector<string>&f(string&s,int i,vector<string>&w,unordered_map<int,vector<string>>&m){if(m.count(i))return m[i];vector<string>r;if(i==s.size()){r.push_back("");m[i]=r;return m[i];}for(auto&x:w)if(i+x.size()<=s.size()&&s.compare(i,x.size(),x)==0)for(auto&tail:f(s,i+x.size(),w,m))r.push_back(x+(tail.empty()?"":" "+tail));m[i]=r;return m[i];}public:vector<string> wordBreak(string s,vector<string>&w){unordered_map<int,vector<string>>m;return f(s,0,w,m);}};
