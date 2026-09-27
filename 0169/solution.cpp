#include <vector>
using namespace std;class Solution{public:int majorityElement(vector<int>&a){int c=0,x=0;for(int v:a){if(!c)x=v;c+=v==x?1:-1;}return x;}};
