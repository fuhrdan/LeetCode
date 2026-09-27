#include <vector>
using namespace std;class Solution{public:int singleNumber(vector<int>&a){int x=0;for(int v:a)x^=v;return x;}};
