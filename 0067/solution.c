#include <stdlib.h>
#include <string.h>
char* addBinary(char*a,char*b){int i=strlen(a)-1,j=strlen(b)-1,n=(i>j?i:j)+3,k=n-1,c=0;char*r=malloc(n);r[k--]=0;while(i>=0||j>=0||c){int s=c+(i>=0?a[i--]-'0':0)+(j>=0?b[j--]-'0':0);r[k--]='0'+s%2;c=s/2;}int st=k+1;memmove(r,r+st,n-st);return r;}
