#include <stdlib.h>
static int cmp(const void*a,const void*b){return(*(int*)a>*(int*)b)-(*(int*)a<*(int*)b);}int* intersection(int*a,int n,int*b,int m,int*rs){qsort(a,n,sizeof(int),cmp);qsort(b,m,sizeof(int),cmp);int*r=malloc((n<m?n:m)*sizeof(int)),i=0,j=0,c=0;while(i<n&&j<m){if(a[i]<b[j])i++;else if(a[i]>b[j])j++;else{if(c==0||r[c-1]!=a[i])r[c++]=a[i];i++;j++;}}*rs=c;return r;}
