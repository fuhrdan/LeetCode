#include <stdlib.h>
#include <string.h>
#include <limits.h>
typedef struct{char**w;int n;}WordDistance;WordDistance* wordDistanceCreate(char**w,int n){WordDistance*x=malloc(sizeof(*x));x->w=w;x->n=n;return x;}int wordDistanceShortest(WordDistance*x,char*a,char*b){int i=-1,j=-1,r=INT_MAX;for(int k=0;k<x->n;k++){if(!strcmp(x->w[k],a))i=k;if(!strcmp(x->w[k],b))j=k;if(i>=0&&j>=0){int d=i-j;if(d<0)d=-d;if(d<r)r=d;}}return r;}void wordDistanceFree(WordDistance*x){free(x);}
