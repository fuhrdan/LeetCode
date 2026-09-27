#include <stdlib.h>
#include <string.h>
static const char*M[]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
static void bt(char*d,int n,int i,char*buf,char***out,int*cnt,int*cap){if(i==n){if(*cnt==*cap){*cap*=2;*out=realloc(*out,*cap*sizeof(char*));}(*out)[*cnt]=malloc(n+1);memcpy((*out)[*cnt],buf,n);(*out)[(*cnt)++][n]=0;return;}for(const char*p=M[d[i]-'0'];*p;p++){buf[i]=*p;bt(d,n,i+1,buf,out,cnt,cap);}}
char** letterCombinations(char*digits,int*returnSize){int n=strlen(digits);if(!n){*returnSize=0;return NULL;}int cap=16,cnt=0;char**out=malloc(cap*sizeof(char*));char*buf=malloc(n);bt(digits,n,0,buf,&out,&cnt,&cap);free(buf);*returnSize=cnt;return out;}
