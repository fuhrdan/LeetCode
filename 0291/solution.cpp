#include <string>
#include <unordered_map>
#include <unordered_set>
using namespace std;class Solution{unordered_map<char,string>m;unordered_set<string>u;bool f(string&p,int i,string&s,int j){if(i==p.size()||j==s.size())return i==p.size()&&j==s.size();char c=p[i];if(m.count(c)){auto&x=m[c];return s.compare(j,x.size(),x)==0&&f(p,i+1,s,j+x.size());}for(int e=j;e<s.size();e++){string x=s.substr(j,e-j+1);if(u.count(x))continue;m[c]=x;u.insert(x);if(f(p,i+1,s,e+1))return true;u.erase(x);m.erase(c);}return false;}public:bool wordPatternMatch(string p,string s){return f(p,0,s,0);}};
