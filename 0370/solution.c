#include <stdlib.h>
int* getModifiedArray(int length,int**u,int n,int*cols,int*rs){int*r=calloc(length,sizeof(int));for(int i=0;i<n;i++){r[u[i][0]]+=u[i][2];if(u[i][1]+1<length)r[u[i][1]+1]-=u[i][2];}for(int i=1;i<length;i++)r[i]+=r[i-1];*rs=length;return r;}
