#include <vector>
#include <map>
using namespace std;class SummaryRanges{map<int,int>m;public:SummaryRanges(){}void addNum(int v){auto it=m.upper_bound(v);int l=v,r=v;if(it!=m.begin()){auto p=prev(it);if(p->second>=v)return;if(p->second+1==v){l=p->first;r=max(r,p->second);m.erase(p);}}if(it!=m.end()&&it->first==v+1){r=it->second;m.erase(it);}m[l]=r;}vector<vector<int>> getIntervals(){vector<vector<int>>o;for(auto&[l,r]:m)o.push_back({l,r});return o;}};
