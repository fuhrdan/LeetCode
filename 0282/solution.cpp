#include <string>
#include <vector>
using namespace std;class Solution{vector<string>o;void f(string&s,int p,long long v,long long last,string e,long long t){if(p==s.size()){if(v==t)o.push_back(e);return;}long long n=0;for(int i=p;i<s.size();i++){if(i>p&&s[p]=='0')break;n=n*10+s[i]-'0';string x=s.substr(p,i-p+1);if(!p)f(s,i+1,n,n,x,t);else{f(s,i+1,v+n,n,e+"+"+x,t);f(s,i+1,v-n,-n,e+"-"+x,t);f(s,i+1,v-last+last*n,last*n,e+"*"+x,t);}}}public:vector<string> addOperators(string s,int t){f(s,0,0,0,"",t);return o;}};
