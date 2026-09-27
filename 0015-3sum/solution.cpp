#include <vector>
#include <algorithm>
using namespace std;
class Solution{public:vector<vector<int>> threeSum(vector<int>&a){sort(a.begin(),a.end());vector<vector<int>>o;for(int i=0;i+2<a.size();i++){if(i&&a[i]==a[i-1])continue;int l=i+1,r=a.size()-1;while(l<r){long s=(long)a[i]+a[l]+a[r];if(s<0)l++;else if(s>0)r--;else{o.push_back({a[i],a[l],a[r]});int x=a[l],y=a[r];while(l<r&&a[l]==x)l++;while(l<r&&a[r]==y)r--;}}}return o;}};
