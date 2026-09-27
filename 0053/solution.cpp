#include <vector>
#include <algorithm>
using namespace std;class Solution{public:int maxSubArray(vector<int>&a){int c=a[0],b=a[0];for(int i=1;i<a.size();i++){c=max(a[i],c+a[i]);b=max(b,c);}return b;}};
