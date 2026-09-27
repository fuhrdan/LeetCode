#include <vector>
#include <algorithm>
using namespace std;class Solution{public:vector<int> largestDivisibleSubset(vector<int>&a){if(a.empty())return{};sort(a.begin(),a.end());int n=a.size(),best=0;vector<int>d(n,1),p(n,-1);for(int i=0;i<n;i++){for(int j=0;j<i;j++)if(a[i]%a[j]==0&&d[j]+1>d[i])d[i]=d[j]+1,p[i]=j;if(d[i]>d[best])best=i;}vector<int>o;for(int i=best;i!=-1;i=p[i])o.push_back(a[i]);reverse(o.begin(),o.end());return o;}};
