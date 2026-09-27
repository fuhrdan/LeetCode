#include <stdlib.h>
static int cmp128(const void*a,const void*b){int x=*(int*)a,y=*(int*)b;return(x>y)-(x<y);}int longestConsecutive(int*a,int n){if(!n)return 0;qsort(a,n,sizeof(int),cmp128);int b=1,c=1;for(int i=1;i<n;i++){if(a[i]==a[i-1])continue;if(a[i]==a[i-1]+1)c++;else c=1;if(c>b)b=c;}return b;}
