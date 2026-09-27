#include <vector>
using namespace std;class Solution{public:int singleNumber(vector<int>&a){int o=0,t=0;for(int x:a){o=(o^x)&~t;t=(t^x)&~o;}return o;}};
