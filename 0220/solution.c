#include <stdbool.h>
#include <stdlib.h>
typedef struct{long long id,val;}B220;bool containsNearbyAlmostDuplicate(int*a,int n,int indexDiff,int valueDiff){if(valueDiff<0)return false;long long w=(long long)valueDiff+1;B220*b=malloc((indexDiff+2)*sizeof(B220));int c=0;for(int i=0;i<n;i++){long long x=a[i],id=x>=0?x/w:((x+1)/w)-1;for(int j=0;j<c;j++)if(b[j].id==id||((b[j].id==id-1||b[j].id==id+1)&&llabs(x-b[j].val)<=valueDiff)){free(b);return true;}b[c++]=(B220){id,x};if(c>indexDiff){for(int j=1;j<c;j++)b[j-1]=b[j];c--;}}free(b);return false;}
