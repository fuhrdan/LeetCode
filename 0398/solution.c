#include <stdlib.h>
typedef struct{int*a,n;}Solution;Solution* solutionCreate(int*a,int n){Solution*x=malloc(sizeof(*x));x->a=a;x->n=n;return x;}int solutionPick(Solution*x,int target){int ans=-1,c=0;for(int i=0;i<x->n;i++)if(x->a[i]==target){c++;if(rand()%c==0)ans=i;}return ans;}void solutionFree(Solution*x){free(x);}
