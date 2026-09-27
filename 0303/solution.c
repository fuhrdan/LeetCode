#include <stdlib.h>
typedef struct{long long*p;}NumArray;NumArray* numArrayCreate(int*a,int n){NumArray*x=malloc(sizeof(*x));x->p=malloc((n+1)*sizeof(long long));x->p[0]=0;for(int i=0;i<n;i++)x->p[i+1]=x->p[i]+a[i];return x;}int numArraySumRange(NumArray*x,int l,int r){return x->p[r+1]-x->p[l];}void numArrayFree(NumArray*x){free(x->p);free(x);}
