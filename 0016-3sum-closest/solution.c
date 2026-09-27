#include <stdlib.h>
#include <limits.h>
static int cmp(const void*a,const void*b){int x=*(int*)a,y=*(int*)b;return(x>y)-(x<y);}
int threeSumClosest(int*a,int n,int target){qsort(a,n,sizeof(int),cmp);int best=a[0]+a[1]+a[2];for(int i=0;i<n-2;i++){int l=i+1,r=n-1;while(l<r){int s=a[i]+a[l]+a[r];if(abs(target-s)<abs(target-best))best=s;if(s<target)l++;else if(s>target)r--;else return target;}}return best;}
