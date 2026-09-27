#include <vector>
#include <set>
#include <climits>
using namespace std;class Solution{public:int maxSumSubmatrix(vector<vector<int>>&a,int k){int m=a.size(),n=a[0].size(),best=INT_MIN;for(int top=0;top<m;top++){vector<int>s(n);for(int bot=top;bot<m;bot++){for(int c=0;c<n;c++)s[c]+=a[bot][c];set<int>p{0};int cur=0;for(int x:s){cur+=x;auto it=p.lower_bound(cur-k);if(it!=p.end())best=max(best,cur-*it);p.insert(cur);}}}return best;}};
