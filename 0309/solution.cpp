#include <vector>
#include <algorithm>
using namespace std;class Solution{public:int maxProfit(vector<int>&a){if(a.empty())return 0;int h=-a[0],s=0,r=0;for(int i=1;i<a.size();i++){int ph=h,ps=s;h=max(h,r-a[i]);s=ph+a[i];r=max(r,ps);}return max(s,r);}};
