#include <limits.h>
int maxProfit(int*p,int n){int b1=INT_MIN,s1=0,b2=INT_MIN,s2=0;for(int i=0;i<n;i++){if(-p[i]>b1)b1=-p[i];if(b1+p[i]>s1)s1=b1+p[i];if(s1-p[i]>b2)b2=s1-p[i];if(b2+p[i]>s2)s2=b2+p[i];}return s2;}
