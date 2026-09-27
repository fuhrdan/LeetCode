#include <stdlib.h>
int* productExceptSelf(int*a,int n,int*rs){int*r=malloc(n*sizeof(int)),p=1;for(int i=0;i<n;i++){r[i]=p;p*=a[i];}p=1;for(int i=n-1;i>=0;i--){r[i]*=p;p*=a[i];}*rs=n;return r;}
