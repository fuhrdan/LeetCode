#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
bool wordPattern(char*p,char*s){char*copy=strdup(s);char*w[300];int n=0;for(char*t=strtok(copy," ");t;t=strtok(NULL," "))w[n++]=t;if(strlen(p)!=n){free(copy);return false;}for(int i=0;i<n;i++)for(int j=0;j<i;j++)if((p[i]==p[j])!=(!strcmp(w[i],w[j]))){free(copy);return false;}free(copy);return true;}
