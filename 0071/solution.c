#include <stdlib.h>
#include <string.h>
char* simplifyPath(char*p){char*copy=strdup(p),*tok,*save,*parts[2048];int n=0;for(tok=strtok_r(copy,"/",&save);tok;tok=strtok_r(NULL,"/",&save)){if(strcmp(tok,".")==0)continue;if(strcmp(tok,"..")==0){if(n)n--;}else parts[n++]=tok;}size_t len=1;for(int i=0;i<n;i++)len+=strlen(parts[i])+1;char*r=malloc(len+1),*q=r;*q++='/';for(int i=0;i<n;i++){int z=strlen(parts[i]);memcpy(q,parts[i],z);q+=z;if(i+1<n)*q++='/';}*q=0;free(copy);return r;}
