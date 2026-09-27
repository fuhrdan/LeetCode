#include <stdbool.h>
bool isPerfectSquare(int n){long l=1,r=n;while(l<=r){long m=(l+r)/2,v=m*m;if(v==n)return true;if(v<n)l=m+1;else r=m-1;}return false;}
