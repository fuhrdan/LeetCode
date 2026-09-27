#include <vector>
using namespace std;class Solution{public:int combinationSum4(vector<int>&a,int target){vector<unsigned long long>d(target+1);d[0]=1;for(int t=1;t<=target;t++)for(int x:a)if(x<=t)d[t]+=d[t-x];return d[target];}};
