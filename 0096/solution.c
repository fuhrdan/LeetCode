#include <stdlib.h>
int numTrees(int n){int*d=calloc(n+1,sizeof(int));d[0]=1;if(n)d[1]=1;for(int x=2;x<=n;x++)for(int r=1;r<=x;r++)d[x]+=d[r-1]*d[x-r];int v=d[n];free(d);return v;}
