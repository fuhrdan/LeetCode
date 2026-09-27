#include <string>
#include <sstream>
#include <unordered_map>
using namespace std;class Solution{public:bool wordPattern(string p,string s){stringstream ss(s);unordered_map<char,string>a;unordered_map<string,char>b;string w;int i=0;while(ss>>w){if(i==p.size())return false;if(a.count(p[i])&&a[p[i]]!=w||b.count(w)&&b[w]!=p[i])return false;a[p[i]]=w;b[w]=p[i];i++;}return i==p.size();}};
