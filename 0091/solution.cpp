#include <string>
using namespace std;class Solution{public:int numDecodings(string s){if(s.empty()||s[0]=='0')return 0;int a=1,b=1;for(int i=1;i<s.size();i++){int c=s[i]!='0'?b:0,x=(s[i-1]-'0')*10+s[i]-'0';if(x>=10&&x<=26)c+=a;a=b;b=c;}return b;}};
