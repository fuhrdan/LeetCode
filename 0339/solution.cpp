#include <vector>
using namespace std;class Solution{int f(const vector<NestedInteger>&a,int d){int s=0;for(auto&x:a)s+=x.isInteger()?x.getInteger()*d:f(x.getList(),d+1);return s;}public:int depthSum(vector<NestedInteger>&a){return f(a,1);}};
