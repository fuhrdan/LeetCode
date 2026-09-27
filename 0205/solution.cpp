#include <string>
using namespace std;class Solution{public:bool isIsomorphic(string s,string t){int a[256]{},b[256]{};for(int i=0;i<s.size();i++){unsigned char x=s[i],y=t[i];if(a[x]!=b[y])return false;a[x]=b[y]=i+1;}return true;}};
