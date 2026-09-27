#include <stdlib.h>
#include <stdio.h>
#include <string.h>
char* encode(char**strs,int n){int total=1;for(int i=0;i<n;i++)total+=20+strlen(strs[i]);char*r=malloc(total);int p=0;for(int i=0;i<n;i++)p+=sprintf(r+p,"%zu#",strlen(strs[i])),memcpy(r+p,strs[i],strlen(strs[i])),p+=strlen(strs[i]);r[p]=0;return r;}char** decode(char*s,int*rs){int cap=16,c=0;char**o=malloc(cap*sizeof(char*));for(int i=0;s[i];){int len=0;while(s[i]!='#')len=len*10+s[i++]-'0';i++;if(c==cap){cap*=2;o=realloc(o,cap*sizeof(char*));}o[c]=malloc(len+1);memcpy(o[c],s+i,len);o[c][len]=0;c++;i+=len;}*rs=c;return o;}
