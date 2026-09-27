#include <stdbool.h>
#include <limits.h>
bool increasingTriplet(int*a,int n){int x=INT_MAX,y=INT_MAX;for(int i=0;i<n;i++)if(a[i]<=x)x=a[i];else if(a[i]<=y)y=a[i];else return true;return false;}
