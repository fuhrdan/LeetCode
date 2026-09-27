#include <limits.h>
int minSubArrayLen(int target,int*a,int n){int l=0,sum=0,b=INT_MAX;for(int r=0;r<n;r++){sum+=a[r];while(sum>=target){if(r-l+1<b)b=r-l+1;sum-=a[l++];}}return b==INT_MAX?0:b;}
