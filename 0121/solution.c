#include <limits.h>
int maxProfit(int*p,int n){int mn=INT_MAX,b=0;for(int i=0;i<n;i++){if(p[i]<mn)mn=p[i];if(p[i]-mn>b)b=p[i]-mn;}return b;}
