#include <stdbool.h>
#include <string.h>
bool isStrobogrammatic(char*s){int l=0,r=strlen(s)-1;while(l<=r){char a=s[l],b=s[r],m=a=='0'?'0':a=='1'?'1':a=='6'?'9':a=='8'?'8':a=='9'?'6':'x';if(m!=b)return false;l++;r--;}return true;}
