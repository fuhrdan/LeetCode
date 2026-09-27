#include <stdlib.h>
static int lb(int*a,int n,long long t){int l=0,r=n;while(l<r){int m=(l+r)/2;if(a[m]<t)l=m+1;else r=m;}return l;}int* searchRange(int*a,int n,int t,int*returnSize){int*r=malloc(2*sizeof(int));*returnSize=2;int l=lb(a,n,t),q=lb(a,n,(long long)t+1)-1;if(l>=n||a[l]!=t)l=q=-1;r[0]=l;r[1]=q;return r;}
