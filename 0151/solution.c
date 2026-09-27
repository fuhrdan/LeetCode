#include <stdlib.h>
#include <string.h>
char* reverseWords(char*s){int n=strlen(s);char**w=malloc((n+1)*sizeof(char*));int c=0;char*copy=strdup(s),*tok=strtok(copy," ");while(tok){w[c++]=tok;tok=strtok(NULL," ");}char*r=malloc(n+1);int p=0;for(int i=c-1;i>=0;i--){int z=strlen(w[i]);if(p)r[p++]=' ';memcpy(r+p,w[i],z);p+=z;}r[p]=0;free(w);free(copy);return r;}
