#include <stdlib.h>
int minimumTotal(int**t,int n,int*cols){int*d=malloc(n*sizeof(int));for(int j=0;j<n;j++)d[j]=t[n-1][j];for(int i=n-2;i>=0;i--)for(int j=0;j<=i;j++)d[j]=t[i][j]+(d[j]<d[j+1]?d[j]:d[j+1]);int r=d[0];free(d);return r;}
