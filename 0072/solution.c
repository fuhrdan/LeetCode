#include <stdlib.h>
#include <string.h>
int minDistance(char*a,char*b){int m=strlen(a),n=strlen(b),*d=malloc((n+1)*sizeof(int));for(int j=0;j<=n;j++)d[j]=j;for(int i=1;i<=m;i++){int prev=d[0];d[0]=i;for(int j=1;j<=n;j++){int old=d[j];if(a[i-1]==b[j-1])d[j]=prev;else{int x=d[j]<d[j-1]?d[j]:d[j-1];if(prev<x)x=prev;d[j]=x+1;}prev=old;}}int r=d[n];free(d);return r;}
