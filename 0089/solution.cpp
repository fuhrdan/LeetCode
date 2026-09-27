#include <vector>
using namespace std;class Solution{public:vector<int> grayCode(int n){vector<int>r(1<<n);for(int i=0;i<r.size();i++)r[i]=i^(i>>1);return r;}};
