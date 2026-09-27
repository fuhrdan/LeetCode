#include <stdlib.h>
static int cmp(const void*a,const void*b){return(*(int*)a>*(int*)b)-(*(int*)a<*(int*)b);}void wiggleSort(int*a,int n){int*b=malloc(n*sizeof(int));for(int i=0;i<n;i++)b[i]=a[i];qsort(b,n,sizeof(int),cmp);int l=(n-1)/2,r=n-1;for(int i=0;i<n;i++)a[i]=(i%2==0)?b[l--]:b[r--];free(b);}
