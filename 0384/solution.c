#include <stdlib.h>
#include <string.h>
typedef struct{int*orig,n;}Solution;Solution* solutionCreate(int*a,int n){Solution*x=malloc(sizeof(*x));x->n=n;x->orig=malloc(n*sizeof(int));memcpy(x->orig,a,n*sizeof(int));return x;}int* solutionReset(Solution*x,int*rs){int*r=malloc(x->n*sizeof(int));memcpy(r,x->orig,x->n*sizeof(int));*rs=x->n;return r;}int* solutionShuffle(Solution*x,int*rs){int*r=solutionReset(x,rs);for(int i=x->n-1;i>0;i--){int j=rand()%(i+1),t=r[i];r[i]=r[j];r[j]=t;}return r;}void solutionFree(Solution*x){free(x->orig);free(x);}
