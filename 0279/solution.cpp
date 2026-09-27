#include <vector>
#include <algorithm>
using namespace std;class Solution{public:int numSquares(int n){vector<int>d(n+1);for(int i=1;i<=n;i++){d[i]=i;for(int j=1;j*j<=i;j++)d[i]=min(d[i],d[i-j*j]+1);}return d[n];}};
