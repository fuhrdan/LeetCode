#include <vector>
#include <algorithm>
using namespace std;class Solution{public:vector<int> countSmaller(vector<int>&a){vector<int>v=a;sort(v.begin(),v.end());v.erase(unique(v.begin(),v.end()),v.end());vector<int>b(v.size()+1),o(a.size());auto sum=[&](int i){int r=0;for(;i;i-=i&-i)r+=b[i];return r;};for(int i=a.size()-1;i>=0;i--){int r=lower_bound(v.begin(),v.end(),a[i])-v.begin()+1;o[i]=sum(r-1);for(int x=r;x<b.size();x+=x&-x)b[x]++;}return o;}};
