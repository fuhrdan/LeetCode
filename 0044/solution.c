#include <stdbool.h>
bool isMatch(char*s,char*p){int i=0,j=0,star=-1,mark=0;while(s[i]){if(p[j]=='?'||p[j]==s[i]){i++;j++;}else if(p[j]=='*'){star=j++;mark=i;}else if(star>=0){j=star+1;i=++mark;}else return false;}while(p[j]=='*')j++;return p[j]==0;}
