#include <stdlib.h>
int uniquePaths(int m,int n){int*d=malloc(n*sizeof(int));for(int j=0;j<n;j++)d[j]=1;for(int i=1;i<m;i++)for(int j=1;j<n;j++)d[j]+=d[j-1];int r=d[n-1];free(d);return r;}
