#include <stdlib.h>
#include <stdio.h>
char** summaryRanges(int*a,int n,int*rs){char**o=malloc(n*sizeof(char*));int c=0;for(int i=0;i<n;){int j=i;while(j+1<n&&(long long)a[j+1]==(long long)a[j]+1)j++;o[c]=malloc(64);if(i==j)sprintf(o[c],"%d",a[i]);else sprintf(o[c],"%d->%d",a[i],a[j]);c++;i=j+1;}*rs=c;return o;}
