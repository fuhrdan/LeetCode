#include <stdlib.h>
static void f(int n,int k,int st,int*b,int len,int***o,int*c,int*cap){if(len==k){if(*c==*cap){*cap*=2;*o=realloc(*o,*cap*sizeof(int*));}(*o)[*c]=malloc(k*sizeof(int));for(int i=0;i<k;i++)(*o)[*c][i]=b[i];(*c)++;return;}for(int x=st;x<=n-(k-len)+1;x++){b[len]=x;f(n,k,x+1,b,len+1,o,c,cap);}}
int** combine(int n,int k,int*rs,int**rc){int cap=16,c=0,**o=malloc(cap*sizeof(int*)),*b=malloc(k*sizeof(int));f(n,k,1,b,0,&o,&c,&cap);int*cols=malloc(c*sizeof(int));for(int i=0;i<c;i++)cols[i]=k;free(b);*rs=c;*rc=cols;return o;}
