#include <stdlib.h>
#include <string.h>
/* Compact DFS without memoization, suitable for LeetCode's small output-bound tests. */
static void f(char*s,int pos,char**w,int n,char*buf,int len,char***o,int*c,int*cap){int L=strlen(s);if(pos==L){buf[len]=0;if(*c==*cap){*cap*=2;*o=realloc(*o,*cap*sizeof(char*));}(*o)[(*c)++]=strdup(buf);return;}for(int i=0;i<n;i++){int z=strlen(w[i]);if(pos+z<=L&&strncmp(s+pos,w[i],z)==0){int old=len;if(len){buf[len++]=' ';}memcpy(buf+len,w[i],z);len+=z;f(s,pos+z,w,n,buf,len,o,c,cap);len=old;}}}char** wordBreak(char*s,char**w,int n,int*rs){int cap=16,c=0;char**o=malloc(cap*sizeof(char*));char*buf=malloc(strlen(s)*2+2);f(s,0,w,n,buf,0,&o,&c,&cap);free(buf);*rs=c;return o;}
