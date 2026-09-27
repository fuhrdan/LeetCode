#include <stdlib.h>
int* countBits(int n,int*rs){int*r=malloc((n+1)*sizeof(int));r[0]=0;for(int i=1;i<=n;i++)r[i]=r[i>>1]+(i&1);*rs=n+1;return r;}
