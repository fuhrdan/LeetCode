#include <climits>
class Solution{public:int divide(int a,int b){if(a==INT_MIN&&b==-1)return INT_MAX;long long x=a,y=b;bool neg=(x<0)^(y<0);x=x<0?-x:x;y=y<0?-y:y;long long q=0;for(int i=31;i>=0;i--)if((x>>i)>=y){x-=y<<i;q+=1LL<<i;}return neg?-q:q;}};
