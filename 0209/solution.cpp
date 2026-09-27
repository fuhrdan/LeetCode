#include <vector>
#include <climits>
#include <algorithm>
using namespace std;class Solution{public:int minSubArrayLen(int t,vector<int>&a){int l=0,s=0,b=INT_MAX;for(int r=0;r<a.size();r++){s+=a[r];while(s>=t){b=min(b,r-l+1);s-=a[l++];}}return b==INT_MAX?0:b;}};
