#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
bool isInterleave(char*a,char*b,char*c){int m=strlen(a),n=strlen(b);if(strlen(c)!=m+n)return false;bool*d=calloc(n+1,sizeof(bool));d[0]=true;for(int j=1;j<=n;j++)d[j]=d[j-1]&&b[j-1]==c[j-1];for(int i=1;i<=m;i++){d[0]=d[0]&&a[i-1]==c[i-1];for(int j=1;j<=n;j++)d[j]=(d[j]&&a[i-1]==c[i+j-1])||(d[j-1]&&b[j-1]==c[i+j-1]);}bool r=d[n];free(d);return r;}
