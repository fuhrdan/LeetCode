#include <stdlib.h>
static int f(int*p,int x){return p[x]==x?x:(p[x]=f(p,p[x]));}int countComponents(int n,int**e,int m,int*cols){int*p=malloc(n*sizeof(int));for(int i=0;i<n;i++)p[i]=i;int c=n;for(int i=0;i<m;i++){int a=f(p,e[i][0]),b=f(p,e[i][1]);if(a!=b){p[a]=b;c--;}}free(p);return c;}
