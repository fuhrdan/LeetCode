#include <stdlib.h>
int numSquares(int n){int*d=malloc((n+1)*sizeof(int));d[0]=0;for(int i=1;i<=n;i++){d[i]=i;for(int j=1;j*j<=i;j++)if(d[i-j*j]+1<d[i])d[i]=d[i-j*j]+1;}int r=d[n];free(d);return r;}
