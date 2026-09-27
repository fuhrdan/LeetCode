#include <stdlib.h>
int minTotalDistance(int**g,int m,int*cols){int n=cols[0],*r=malloc(m*n*sizeof(int)),*c=malloc(m*n*sizeof(int)),k=0;for(int i=0;i<m;i++)for(int j=0;j<n;j++)if(g[i][j])r[k++]=i;int q=0;for(int j=0;j<n;j++)for(int i=0;i<m;i++)if(g[i][j])c[q++]=j;int mr=r[k/2],mc=c[k/2],s=0;for(int i=0;i<k;i++){int a=r[i]-mr;if(a<0)a=-a;int b=c[i]-mc;if(b<0)b=-b;s+=a+b;}free(r);free(c);return s;}
