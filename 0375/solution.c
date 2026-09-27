#include <stdlib.h>
#include <limits.h>
int getMoneyAmount(int n){int**d=malloc((n+2)*sizeof(int*));for(int i=0;i<n+2;i++)d[i]=calloc(n+2,sizeof(int));for(int len=2;len<=n;len++)for(int l=1;l+len-1<=n;l++){int r=l+len-1,b=INT_MAX;for(int x=l;x<=r;x++){int a=d[l][x-1],c=d[x+1][r],v=x+(a>c?a:c);if(v<b)b=v;}d[l][r]=b;}int ret=d[1][n];for(int i=0;i<n+2;i++)free(d[i]);free(d);return ret;}
