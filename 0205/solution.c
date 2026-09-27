#include <stdbool.h>
bool isIsomorphic(char*s,char*t){int a[256]={0},b[256]={0};for(int i=0;s[i];i++){unsigned char x=s[i],y=t[i];if(a[x]!=b[y])return false;a[x]=b[y]=i+1;}return true;}
