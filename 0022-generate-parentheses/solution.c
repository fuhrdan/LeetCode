#include <stdlib.h>
#include <string.h>
static void gen(int n,int o,int c,char*b,int k,char***r,int*cnt,int*cap){if(k==2*n){if(*cnt==*cap){*cap*=2;*r=realloc(*r,*cap*sizeof(char*));}(*r)[*cnt]=malloc(k+1);memcpy((*r)[*cnt],b,k);(*r)[(*cnt)++][k]=0;return;}if(o<n){b[k]='(';gen(n,o+1,c,b,k+1,r,cnt,cap);}if(c<o){b[k]=')';gen(n,o,c+1,b,k+1,r,cnt,cap);}}
char** generateParenthesis(int n,int*returnSize){int cap=16,c=0;char**r=malloc(cap*sizeof(char*));char*b=malloc(2*n);gen(n,0,0,b,0,&r,&c,&cap);free(b);*returnSize=c;return r;}
