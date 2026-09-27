#include <stdlib.h>
static int f(int x,int a,int b,int c){return a*x*x+b*x+c;}int* sortTransformedArray(int*nums,int n,int a,int b,int c,int*rs){int*r=malloc(n*sizeof(int)),l=0,h=n-1,k=a>=0?n-1:0;while(l<=h){int x=f(nums[l],a,b,c),y=f(nums[h],a,b,c);if(a>=0){if(x>y){r[k--]=x;l++;}else{r[k--]=y;h--;}}else{if(x<y){r[k++]=x;l++;}else{r[k++]=y;h--;}}}*rs=n;return r;}
