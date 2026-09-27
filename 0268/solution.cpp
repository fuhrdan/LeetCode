#include <vector>
using namespace std;class Solution{public:int missingNumber(vector<int>&a){int x=a.size();for(int i=0;i<a.size();i++)x^=i^a[i];return x;}};
