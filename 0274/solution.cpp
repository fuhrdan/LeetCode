#include <vector>
#include <algorithm>
using namespace std;class Solution{public:int hIndex(vector<int>&a){sort(a.begin(),a.end());for(int i=0;i<a.size();i++)if(a[i]>=a.size()-i)return a.size()-i;return 0;}};
