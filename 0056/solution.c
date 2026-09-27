#include <stdlib.h>
static int cmp56(const void*a,const void*b){int*const*x=a,*const*y=b;return((*x)[0]>(*y)[0])-((*x)[0]<(*y)[0]);}
int** merge(int**in,int n,int*cols,int*rs,int**rc){qsort(in,n,sizeof(int*),cmp56);int**o=malloc(n*sizeof(int*));int*c=malloc(n*sizeof(int)),k=0;for(int i=0;i<n;i++){if(!k||in[i][0]>o[k-1][1]){o[k]=malloc(2*sizeof(int));o[k][0]=in[i][0];o[k][1]=in[i][1];c[k++]=2;}else if(in[i][1]>o[k-1][1])o[k-1][1]=in[i][1];}*rs=k;*rc=c;return o;}
