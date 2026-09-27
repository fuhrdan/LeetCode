#include <vector>
#include <algorithm>
using namespace std;class Solution{public:int lengthOfLIS(vector<int>&a){vector<int>t;for(int x:a){auto it=lower_bound(t.begin(),t.end(),x);if(it==t.end())t.push_back(x);else *it=x;}return t.size();}};
