#include <string>
using namespace std;class Solution{public:string getHint(string s,string g){int b=0,c=0,a[10]{},x[10]{};for(int i=0;i<s.size();i++)if(s[i]==g[i])b++;else a[s[i]-'0']++,x[g[i]-'0']++;for(int i=0;i<10;i++)c+=min(a[i],x[i]);return to_string(b)+"A"+to_string(c)+"B";}};
