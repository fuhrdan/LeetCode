#include <stdlib.h>
int coinChange(int*c,int n,int amount){int*d=malloc((amount+1)*sizeof(int));d[0]=0;for(int i=1;i<=amount;i++)d[i]=amount+1;for(int i=1;i<=amount;i++)for(int j=0;j<n;j++)if(c[j]<=i&&d[i-c[j]]+1<d[i])d[i]=d[i-c[j]]+1;int r=d[amount]>amount?-1:d[amount];free(d);return r;}
