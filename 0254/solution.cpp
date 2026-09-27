#include <vector>
using namespace std;class Solution{vector<vector<int>>o;void f(int n,int st,vector<int>&v){for(int x=st;x*x<=n;x++)if(n%x==0){v.push_back(x);v.push_back(n/x);o.push_back(v);v.pop_back();f(n/x,x,v);v.pop_back();}}public:vector<vector<int>> getFactors(int n){vector<int>v;f(n,2,v);return o;}};
