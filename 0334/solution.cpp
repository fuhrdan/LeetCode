#include <vector>
#include <climits>
using namespace std;class Solution{public:bool increasingTriplet(vector<int>&a){int x=INT_MAX,y=INT_MAX;for(int v:a)if(v<=x)x=v;else if(v<=y)y=v;else return true;return false;}};
