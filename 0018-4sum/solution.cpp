#include <vector>
#include <algorithm>
using namespace std;class Solution{public:vector<vector<int>> fourSum(vector<int>&a,int t){sort(a.begin(),a.end());vector<vector<int>>o;int n=a.size();for(int i=0;i<n-3;i++){if(i&&a[i]==a[i-1])continue;for(int j=i+1;j<n-2;j++){if(j>i+1&&a[j]==a[j-1])continue;int l=j+1,r=n-1;while(l<r){long long s=(long long)a[i]+a[j]+a[l]+a[r];if(s<t)l++;else if(s>t)r--;else{o.push_back({a[i],a[j],a[l],a[r]});int x=a[l],y=a[r];while(l<r&&a[l]==x)l++;while(l<r&&a[r]==y)r--;}}}}return o;}};
