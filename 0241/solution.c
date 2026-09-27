#include <stdlib.h>
#include <string.h>
int* diffWaysToCompute(char*s,int*rs){int cap=16,c=0,*o=malloc(cap*sizeof(int));for(int i=0;s[i];i++)if(s[i]=='+'||s[i]=='-'||s[i]=='*'){char op=s[i];char*l=strndup(s,i),*r=strdup(s+i+1);int lc,rc;int*A=diffWaysToCompute(l,&lc),*B=diffWaysToCompute(r,&rc);for(int a=0;a<lc;a++)for(int b=0;b<rc;b++){if(c==cap){cap*=2;o=realloc(o,cap*sizeof(int));}o[c++]=op=='+'?A[a]+B[b]:op=='-'?A[a]-B[b]:A[a]*B[b];}free(A);free(B);free(l);free(r);}if(!c)o[c++]=atoi(s);*rs=c;return o;}
