#include <stdlib.h>
#include <string.h>
static void f(char*b,int n,int l,int r,char***o,int*c,int*cap){static char p[5][2]={{'0','0'},{'1','1'},{'6','9'},{'8','8'},{'9','6'}};if(l>r){if(*c==*cap){*cap*=2;*o=realloc(*o,*cap*sizeof(char*));}(*o)[(*c)++]=strdup(b);return;}for(int i=0;i<5;i++){if(l==0&&r>0&&p[i][0]=='0')continue;if(l==r&&p[i][0]!=p[i][1])continue;b[l]=p[i][0];b[r]=p[i][1];f(b,n,l+1,r-1,o,c,cap);}}char** findStrobogrammatic(int n,int*rs){int cap=16,c=0;char**o=malloc(cap*sizeof(char*));char*b=malloc(n+1);b[n]=0;f(b,n,0,n-1,&o,&c,&cap);free(b);*rs=c;return o;}
