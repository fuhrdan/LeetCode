#include <stdlib.h>
int maximalSquare(char**m,int rows,int*cols){if(!rows)return 0;int n=cols[0],*d=calloc(n+1,sizeof(int)),best=0;for(int i=1;i<=rows;i++){int prev=0;for(int j=1;j<=n;j++){int old=d[j];if(m[i-1][j-1]=='1'){int x=d[j]<d[j-1]?d[j]:d[j-1];if(prev<x)x=prev;d[j]=x+1;if(d[j]>best)best=d[j];}else d[j]=0;prev=old;}}free(d);return best*best;}
