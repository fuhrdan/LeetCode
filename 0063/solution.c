#include <stdlib.h>
int uniquePathsWithObstacles(int**g,int m,int*cols){int n=cols[0],*d=calloc(n,sizeof(int));d[0]=1;for(int i=0;i<m;i++)for(int j=0;j<n;j++)if(g[i][j])d[j]=0;else if(j)d[j]+=d[j-1];int r=d[n-1];free(d);return r;}
