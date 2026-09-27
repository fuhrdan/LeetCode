#include <stdlib.h>
int* twoSum(int*a,int n,int t,int*rs){int l=0,r=n-1;while(l<r){int s=a[l]+a[r];if(s==t){int*x=malloc(2*sizeof(int));x[0]=l+1;x[1]=r+1;*rs=2;return x;}if(s<t)l++;else r--;}*rs=0;return NULL;}
