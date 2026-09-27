#include <string>
using namespace std;class Solution{public:int compareVersion(string a,string b){int i=0,j=0;while(i<a.size()||j<b.size()){long x=0,y=0;while(i<a.size()&&a[i]!='.')x=x*10+a[i++]-'0';while(j<b.size()&&b[j]!='.')y=y*10+b[j++]-'0';if(x<y)return-1;if(x>y)return 1;i++;j++;}return 0;}};
