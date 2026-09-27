#include <vector>
#include <algorithm>
#include <climits>
using namespace std;class Solution{public:int maxProfit(vector<int>&p){int mn=INT_MAX,b=0;for(int x:p){mn=min(mn,x);b=max(b,x-mn);}return b;}};
