#include <vector>
#include <algorithm>
using namespace std;class Solution{public:int threeSumSmaller(vector<int>&a,int t){sort(a.begin(),a.end());int c=0;for(int i=0;i+2<a.size();i++){int l=i+1,r=a.size()-1;while(l<r){if(a[i]+a[l]+a[r]<t){c+=r-l;l++;}else r--;}}return c;}};
