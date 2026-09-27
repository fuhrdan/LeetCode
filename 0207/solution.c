#include <stdlib.h>
#include <stdbool.h>
bool canFinish(int n,int**p,int ps,int*cols){int*deg=calloc(n,sizeof(int)),*q=malloc(n*sizeof(int));for(int i=0;i<ps;i++)deg[p[i][0]]++;int h=0,t=0,c=0;for(int i=0;i<n;i++)if(!deg[i])q[t++]=i;while(h<t){int u=q[h++];c++;for(int i=0;i<ps;i++)if(p[i][1]==u&&--deg[p[i][0]]==0)q[t++]=p[i][0];}free(deg);free(q);return c==n;}
