#include <stdlib.h>
#include <limits.h>
int nthSuperUglyNumber(int n,int*p,int k){long long*u=malloc(n*sizeof(long long));int*idx=calloc(k,sizeof(int));u[0]=1;for(int i=1;i<n;i++){long long m=LLONG_MAX;for(int j=0;j<k;j++){long long v=u[idx[j]]*p[j];if(v<m)m=v;}u[i]=m;for(int j=0;j<k;j++)if(u[idx[j]]*p[j]==m)idx[j]++;}int r=u[n-1];free(u);free(idx);return r;}
