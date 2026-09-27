#include <stdlib.h>
int* getRow(int n,int*rs){int*r=calloc(n+1,sizeof(int));r[0]=1;for(int i=1;i<=n;i++)for(int j=i;j>0;j--)r[j]+=r[j-1];*rs=n+1;return r;}
