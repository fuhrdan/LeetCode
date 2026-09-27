#include <vector>
#include <algorithm>
#include <cstdlib>
using namespace std;class Solution{public:int threeSumClosest(vector<int>&a,int t){sort(a.begin(),a.end());int b=a[0]+a[1]+a[2];for(int i=0;i+2<a.size();i++){int l=i+1,r=a.size()-1;while(l<r){int s=a[i]+a[l]+a[r];if(abs(t-s)<abs(t-b))b=s;if(s<t)l++;else if(s>t)r--;else return t;}}return b;}};
