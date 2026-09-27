#include <string>
#include <vector>
using namespace std;class Solution{public:string simplifyPath(string p){vector<string>st;for(int i=0;i<p.size();){while(i<p.size()&&p[i]=='/')i++;int j=i;while(j<p.size()&&p[j]!='/')j++;string x=p.substr(i,j-i);if(x==".."){if(!st.empty())st.pop_back();}else if(!x.empty()&&x!=".")st.push_back(x);i=j;}string r;for(auto&x:st)r+="/"+x;return r.empty()?"/":r;}};
