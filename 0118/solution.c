#include <stdlib.h>
int** generate(int n,int*rs,int**rc){int**o=malloc(n*sizeof(int*)),*c=malloc(n*sizeof(int));for(int i=0;i<n;i++){o[i]=malloc((i+1)*sizeof(int));c[i]=i+1;o[i][0]=o[i][i]=1;for(int j=1;j<i;j++)o[i][j]=o[i-1][j-1]+o[i-1][j];}*rs=n;*rc=c;return o;}
