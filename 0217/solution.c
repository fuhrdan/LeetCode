#include <stdbool.h>
#include <stdlib.h>
static int cmp217(const void*a,const void*b){int x=*(int*)a,y=*(int*)b;return(x>y)-(x<y);}bool containsDuplicate(int*a,int n){qsort(a,n,sizeof(int),cmp217);for(int i=1;i<n;i++)if(a[i]==a[i-1])return true;return false;}
