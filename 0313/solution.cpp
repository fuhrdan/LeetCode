#include <vector>
#include <climits>
using namespace std;class Solution{public:int nthSuperUglyNumber(int n,vector<int>&p){vector<long long>u(n,1);vector<int>idx(p.size());for(int i=1;i<n;i++){long long m=LLONG_MAX;for(int j=0;j<p.size();j++)m=min(m,u[idx[j]]*p[j]);u[i]=m;for(int j=0;j<p.size();j++)if(u[idx[j]]*p[j]==m)idx[j]++;}return u.back();}};
