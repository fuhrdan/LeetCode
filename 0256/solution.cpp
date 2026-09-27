#include <vector>
#include <algorithm>
using namespace std;class Solution{public:int minCost(vector<vector<int>>&c){int a=0,b=0,d=0;for(auto&x:c){int na=x[0]+min(b,d),nb=x[1]+min(a,d),nd=x[2]+min(a,b);a=na;b=nb;d=nd;}return min({a,b,d});}};
