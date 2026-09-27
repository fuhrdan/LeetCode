#include <stdlib.h>
char* getPermutation(int n,int k){int fact[10]={1};for(int i=1;i<=n;i++)fact[i]=fact[i-1]*i;int nums[9];for(int i=0;i<n;i++)nums[i]=i+1;char*r=malloc(n+1);k--;for(int p=0;p<n;p++){int f=fact[n-1-p],idx=k/f;k%=f;r[p]='0'+nums[idx];for(int j=idx;j<n-1-p;j++)nums[j]=nums[j+1];}r[n]=0;return r;}
