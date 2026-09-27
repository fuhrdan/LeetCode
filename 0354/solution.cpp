#include <vector>
#include <algorithm>
using namespace std;class Solution{public:int maxEnvelopes(vector<vector<int>>&e){sort(e.begin(),e.end(),[](auto&a,auto&b){return a[0]!=b[0]?a[0]<b[0]:a[1]>b[1];});vector<int>t;for(auto&x:e){auto it=lower_bound(t.begin(),t.end(),x[1]);if(it==t.end())t.push_back(x[1]);else *it=x[1];}return t.size();}};
