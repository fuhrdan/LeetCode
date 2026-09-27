#include <stdbool.h>
#include <stdlib.h>
static int cmp(const void*a,const void*b){int*x=*(int**)a,*y=*(int**)b;return x[0]-y[0];}bool canAttendMeetings(int**a,int n,int*cols){qsort(a,n,sizeof(int*),cmp);for(int i=1;i<n;i++)if(a[i][0]<a[i-1][1])return false;return true;}
