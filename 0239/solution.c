#include <stdlib.h>
int* maxSlidingWindow(int*a,int n,int k,int*rs){if(!n){*rs=0;return NULL;}int*q=malloc(n*sizeof(int)),h=0,t=0,*r=malloc((n-k+1)*sizeof(int)),c=0;for(int i=0;i<n;i++){while(h<t&&q[h]<=i-k)h++;while(h<t&&a[q[t-1]]<=a[i])t--;q[t++]=i;if(i>=k-1)r[c++]=a[q[h]];}free(q);*rs=c;return r;}
