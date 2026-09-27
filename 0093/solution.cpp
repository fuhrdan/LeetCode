#include <string>
#include <vector>
using namespace std;class Solution{vector<string>o;void f(string&s,int p,int part,vector<string>&v){if(part==4){if(p==s.size())o.push_back(v[0]+"."+v[1]+"."+v[2]+"."+v[3]);return;}for(int l=1;l<=3&&p+l<=s.size();l++){if(l>1&&s[p]=='0')break;string x=s.substr(p,l);if(stoi(x)>255)break;v.push_back(x);f(s,p+l,part+1,v);v.pop_back();}}public:vector<string> restoreIpAddresses(string s){vector<string>v;f(s,0,0,v);return o;}};
