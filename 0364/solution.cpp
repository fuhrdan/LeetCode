#include <vector>
using namespace std;class Solution{public:int depthSumInverse(vector<NestedInteger>&a){int un=0,res=0;vector<NestedInteger>cur=a;while(!cur.empty()){vector<NestedInteger>next;for(auto&x:cur)if(x.isInteger())un+=x.getInteger();else for(auto&y:x.getList())next.push_back(y);res+=un;cur.swap(next);}return res;}};
