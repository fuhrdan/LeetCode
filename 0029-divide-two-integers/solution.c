#include <limits.h>
int divide(int a,int b){if(a==INT_MIN&&b==-1)return INT_MAX;int neg=(a<0)^(b<0);unsigned ua=a<0?0u-(unsigned)a:(unsigned)a,ub=b<0?0u-(unsigned)b:(unsigned)b,q=0;for(int i=31;i>=0;i--)if((ua>>i)>=ub){ua-=ub<<i;q|=1u<<i;}return neg?-(int)q:(int)q;}
