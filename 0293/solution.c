#include <stdlib.h>
#include <string.h>
char** generatePossibleNextMoves(char*s,int*rs){int n=strlen(s),c=0;char**o=malloc(n*sizeof(char*));for(int i=0;i+1<n;i++)if(s[i]=='+'&&s[i+1]=='+'){o[c]=strdup(s);o[c][i]=o[c][i+1]='-';c++;}*rs=c;return o;}
