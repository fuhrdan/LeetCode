#include <stdlib.h>
static int cmp(const void*a,const void*b){return(*(int*)a>*(int*)b)-(*(int*)a<*(int*)b);}int threeSumSmaller(int*a,int n,int t){qsort(a,n,sizeof(int),cmp);int c=0;for(int i=0;i<n-2;i++){int l=i+1,r=n-1;while(l<r){if(a[i]+a[l]+a[r]<t){c+=r-l;l++;}else r--;}}return c;}
