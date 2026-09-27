#include <vector>
using namespace std;class Solution{public:vector<int> majorityElement(vector<int>&a){int x=0,y=1,cx=0,cy=0;for(int v:a){if(v==x)cx++;else if(v==y)cy++;else if(!cx)x=v,cx=1;else if(!cy)y=v,cy=1;else cx--,cy--;}cx=cy=0;for(int v:a){if(v==x)cx++;else if(v==y)cy++;}vector<int>o;if(cx>a.size()/3)o.push_back(x);if(cy>a.size()/3)o.push_back(y);return o;}};
