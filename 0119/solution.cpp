#include <vector>
using namespace std;class Solution{public:vector<int> getRow(int n){vector<int>r(n+1);r[0]=1;for(int i=1;i<=n;i++)for(int j=i;j>0;j--)r[j]+=r[j-1];return r;}};
