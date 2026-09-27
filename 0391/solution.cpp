#include <vector>
#include <set>
#include <climits>
using namespace std;class Solution{public:bool isRectangleCover(vector<vector<int>>&r){long long area=0;int x1=INT_MAX,y1=INT_MAX,x2=INT_MIN,y2=INT_MIN;set<pair<int,int>>s;for(auto&a:r){x1=min(x1,a[0]);y1=min(y1,a[1]);x2=max(x2,a[2]);y2=max(y2,a[3]);area+=1LL*(a[2]-a[0])*(a[3]-a[1]);for(auto p:{pair<int,int>{a[0],a[1]},{a[0],a[3]},{a[2],a[1]},{a[2],a[3]}})if(!s.insert(p).second)s.erase(p);}return area==1LL*(x2-x1)*(y2-y1)&&s==set<pair<int,int>>{{x1,y1},{x1,y2},{x2,y1},{x2,y2}};}};
