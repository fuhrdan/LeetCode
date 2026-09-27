#include <stdlib.h>
int lengthOfLIS(int*a,int n){int*t=malloc(n*sizeof(int)),len=0;for(int i=0;i<n;i++){int l=0,r=len;while(l<r){int m=(l+r)/2;if(t[m]<a[i])l=m+1;else r=m;}t[l]=a[i];if(l==len)len++;}free(t);return len;}
