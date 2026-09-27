#include <stdlib.h>
int** multiply(int**a,int m,int*ac,int**b,int bn,int*bc,int*rs,int**rc){int n=bc[0],k=ac[0];int**o=malloc(m*sizeof(int*));*rc=malloc(m*sizeof(int));for(int i=0;i<m;i++){o[i]=calloc(n,sizeof(int));(*rc)[i]=n;for(int x=0;x<k;x++)if(a[i][x])for(int j=0;j<n;j++)if(b[x][j])o[i][j]+=a[i][x]*b[x][j];}*rs=m;return o;}
