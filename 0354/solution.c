#include <stdlib.h>
static int cmp(const void*a,const void*b){int*x=*(int**)a,*y=*(int**)b;return x[0]!=y[0]?x[0]-y[0]:y[1]-x[1];}int maxEnvelopes(int**e,int n,int*cols){qsort(e,n,sizeof(int*),cmp);int*t=malloc(n*sizeof(int)),len=0;for(int i=0;i<n;i++){int l=0,r=len;while(l<r){int m=(l+r)/2;if(t[m]<e[i][1])l=m+1;else r=m;}t[l]=e[i][1];if(l==len)len++;}free(t);return len;}
