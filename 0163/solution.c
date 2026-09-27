#include <stdlib.h>
#include <stdio.h>
#include <string.h>
static char*fmt(long long a,long long b){char*s=malloc(64);if(a==b)sprintf(s,"%lld",a);else sprintf(s,"%lld->%lld",a,b);return s;}char** findMissingRanges(int*a,int n,int lower,int upper,int*rs){char**o=malloc((n+1)*sizeof(char*));int c=0;long long prev=(long long)lower-1;for(int i=0;i<=n;i++){long long cur=i<n?a[i]:(long long)upper+1;if(cur-prev>=2)o[c++]=fmt(prev+1,cur-1);prev=cur;}*rs=c;return o;}
