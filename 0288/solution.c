#include <stdlib.h>
#include <string.h>
typedef struct{char**w;int n;}ValidWordAbbr;ValidWordAbbr* validWordAbbrCreate(char**d,int n){ValidWordAbbr*x=malloc(sizeof(*x));x->w=d;x->n=n;return x;}static void ab(char*s,char*b){int n=strlen(s);if(n<=2)strcpy(b,s);else sprintf(b,"%c%d%c",s[0],n-2,s[n-1]);}bool validWordAbbrIsUnique(ValidWordAbbr*x,char*w){char a[64],b[64];ab(w,a);int seen=0;for(int i=0;i<x->n;i++){ab(x->w[i],b);if(!strcmp(a,b)){if(strcmp(w,x->w[i]))return false;seen=1;}}return true;}void validWordAbbrFree(ValidWordAbbr*x){free(x);}
