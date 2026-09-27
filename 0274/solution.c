#include <stdlib.h>
static int cmp(const void*a,const void*b){return(*(int*)a>*(int*)b)-(*(int*)a<*(int*)b);}int hIndex(int*a,int n){qsort(a,n,sizeof(int),cmp);for(int i=0;i<n;i++)if(a[i]>=n-i)return n-i;return 0;}
