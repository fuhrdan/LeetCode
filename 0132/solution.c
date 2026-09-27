#include <stdlib.h>
#include <string.h>
int minCut(char*s){int n=strlen(s);char*pal=calloc(n*n,1);int*d=malloc((n+1)*sizeof(int));d[0]=-1;for(int i=1;i<=n;i++)d[i]=i-1;for(int r=0;r<n;r++)for(int l=r;l>=0;l--)if(s[l]==s[r]&&(r-l<2||pal[(l+1)*n+r-1])){pal[l*n+r]=1;if(d[l]+1<d[r+1])d[r+1]=d[l]+1;}int x=d[n];free(pal);free(d);return x;}
