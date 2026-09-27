#include <stdbool.h>
bool isUgly(int n){if(n<=0)return false;int p[3]={2,3,5};for(int i=0;i<3;i++)while(n%p[i]==0)n/=p[i];return n==1;}
