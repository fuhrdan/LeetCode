#include <vector>
#include <algorithm>
using namespace std;class Solution{public:int nthUglyNumber(int n){vector<long long>u(n);u[0]=1;int a=0,b=0,c=0;for(int i=1;i<n;i++){u[i]=min({2*u[a],3*u[b],5*u[c]});if(u[i]==2*u[a])a++;if(u[i]==3*u[b])b++;if(u[i]==5*u[c])c++;}return u.back();}};
