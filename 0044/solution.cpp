#include <string>
using namespace std;class Solution{public:bool isMatch(string s,string p){int i=0,j=0,star=-1,mark=0;while(i<s.size()){if(j<p.size()&&(p[j]=='?'||p[j]==s[i])){i++;j++;}else if(j<p.size()&&p[j]=='*'){star=j++;mark=i;}else if(star>=0){j=star+1;i=++mark;}else return false;}while(j<p.size()&&p[j]=='*')j++;return j==p.size();}};
