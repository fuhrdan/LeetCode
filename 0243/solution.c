#include <string.h>
#include <limits.h>
int shortestDistance(char**w,int n,char*a,char*b){int x=-1,y=-1,r=INT_MAX;for(int i=0;i<n;i++){if(!strcmp(w[i],a))x=i;if(!strcmp(w[i],b))y=i;if(x>=0&&y>=0){int d=x-y;if(d<0)d=-d;if(d<r)r=d;}}return r;}
