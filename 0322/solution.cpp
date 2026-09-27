#include <vector>
#include <algorithm>
using namespace std;class Solution{public:int coinChange(vector<int>&c,int a){vector<int>d(a+1,a+1);d[0]=0;for(int i=1;i<=a;i++)for(int x:c)if(x<=i)d[i]=min(d[i],d[i-x]+1);return d[a]>a?-1:d[a];}};
