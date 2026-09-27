#include <stdlib.h>
int combinationSum4(int*a,int n,int target){unsigned long long*d=calloc(target+1,sizeof(unsigned long long));d[0]=1;for(int t=1;t<=target;t++)for(int i=0;i<n;i++)if(a[i]<=t)d[t]+=d[t-a[i]];int r=(int)d[target];free(d);return r;}
