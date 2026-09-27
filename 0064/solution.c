#include <stdlib.h>
#include <limits.h>
int minPathSum(int**g,int m,int*cols){int n=cols[0],*d=malloc(n*sizeof(int));for(int j=0;j<n;j++)d[j]=INT_MAX;d[0]=0;for(int i=0;i<m;i++)for(int j=0;j<n;j++){int left=j?d[j-1]:INT_MAX,up=d[j];int best=left<up?left:up;d[j]=best+g[i][j];}int r=d[n-1];free(d);return r;}
