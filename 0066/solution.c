#include <stdlib.h>
int* plusOne(int*d,int n,int*rs){for(int i=n-1;i>=0;i--){if(d[i]<9){d[i]++;*rs=n;int*r=malloc(n*sizeof(int));for(int j=0;j<n;j++)r[j]=d[j];return r;}d[i]=0;}int*r=calloc(n+1,sizeof(int));r[0]=1;*rs=n+1;return r;}
