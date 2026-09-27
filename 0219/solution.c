#include <stdbool.h>
#include <stdlib.h>
typedef struct{int v,i;}P219;static int cmp219(const void*a,const void*b){const P219*x=a,*y=b;return x->v!=y->v?(x->v>y->v)-(x->v<y->v):x->i-y->i;}bool containsNearbyDuplicate(int*a,int n,int k){P219*p=malloc(n*sizeof(P219));for(int i=0;i<n;i++)p[i]=(P219){a[i],i};qsort(p,n,sizeof(P219),cmp219);for(int i=1;i<n;i++)if(p[i].v==p[i-1].v&&p[i].i-p[i-1].i<=k){free(p);return true;}free(p);return false;}
