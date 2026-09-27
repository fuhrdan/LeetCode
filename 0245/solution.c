#include <string.h>
#include <limits.h>
int shortestWordDistance(char**w,int n,char*a,char*b){int same=!strcmp(a,b),last=-1,x=-1,y=-1,r=INT_MAX;for(int i=0;i<n;i++){if(same){if(!strcmp(w[i],a)){if(last>=0&&i-last<r)r=i-last;last=i;}}else{if(!strcmp(w[i],a))x=i;if(!strcmp(w[i],b))y=i;if(x>=0&&y>=0){int d=x-y;if(d<0)d=-d;if(d<r)r=d;}}}return r;}
