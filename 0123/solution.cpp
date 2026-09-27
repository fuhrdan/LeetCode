#include <vector>
#include <climits>
#include <algorithm>
using namespace std;class Solution{public:int maxProfit(vector<int>&p){int b1=INT_MIN,s1=0,b2=INT_MIN,s2=0;for(int x:p){b1=max(b1,-x);s1=max(s1,b1+x);b2=max(b2,s1-x);s2=max(s2,b2+x);}return s2;}};
