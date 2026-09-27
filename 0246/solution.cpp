#include <string>
using namespace std;class Solution{public:bool isStrobogrammatic(string s){int l=0,r=s.size()-1;while(l<=r){char a=s[l],b=s[r],m=a=='0'?'0':a=='1'?'1':a=='6'?'9':a=='8'?'8':a=='9'?'6':'x';if(m!=b)return false;l++;r--;}return true;}};
