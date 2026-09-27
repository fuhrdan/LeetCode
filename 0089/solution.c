#include <stdlib.h>
int* grayCode(int n,int*rs){int m=1<<n,*r=malloc(m*sizeof(int));for(int i=0;i<m;i++)r[i]=i^(i>>1);*rs=m;return r;}
