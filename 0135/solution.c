#include <stdlib.h>
int candy(int*r,int n){int*c=malloc(n*sizeof(int));for(int i=0;i<n;i++)c[i]=1;for(int i=1;i<n;i++)if(r[i]>r[i-1])c[i]=c[i-1]+1;for(int i=n-2;i>=0;i--)if(r[i]>r[i+1]&&c[i]<=c[i+1])c[i]=c[i+1]+1;int s=0;for(int i=0;i<n;i++)s+=c[i];free(c);return s;}
