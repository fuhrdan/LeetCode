#include <vector>
#include <algorithm>
using namespace std;class Solution{public:int maxProduct(vector<int>&a){int mx=a[0],mn=a[0],b=a[0];for(int i=1;i<a.size();i++){int x=a[i];if(x<0)swap(mx,mn);mx=max(x,mx*x);mn=min(x,mn*x);b=max(b,mx);}return b;}};
