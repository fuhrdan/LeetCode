#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
bool wordBreak(char*s,char**w,int n){int L=strlen(s);bool*d=calloc(L+1,sizeof(bool));d[0]=true;for(int i=1;i<=L;i++)for(int j=0;j<n;j++){int z=strlen(w[j]);if(z<=i&&d[i-z]&&strncmp(s+i-z,w[j],z)==0){d[i]=true;break;}}bool r=d[L];free(d);return r;}
