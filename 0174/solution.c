#include <stdlib.h>
#include <limits.h>
int calculateMinimumHP(int**d,int m,int*cols){int n=cols[0],*dp=malloc((n+1)*sizeof(int));for(int j=0;j<=n;j++)dp[j]=INT_MAX/2;dp[n-1]=1;for(int i=m-1;i>=0;i--)for(int j=n-1;j>=0;j--){int need=(dp[j]<dp[j+1]?dp[j]:dp[j+1])-d[i][j];dp[j]=need>1?need:1;}int r=dp[0];free(dp);return r;}
