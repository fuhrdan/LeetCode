#include <stdlib.h>
int* singleNumber(int*a,int n,int*rs){int x=0;for(int i=0;i<n;i++)x^=a[i];unsigned bit=(unsigned)x&-(unsigned)x;int p=0,q=0;for(int i=0;i<n;i++)if((unsigned)a[i]&bit)p^=a[i];else q^=a[i];int*r=malloc(2*sizeof(int));r[0]=p;r[1]=q;*rs=2;return r;}
