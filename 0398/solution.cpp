#include <vector>
#include <cstdlib>
using namespace std;class Solution{vector<int>a;public:Solution(vector<int>&nums):a(nums){}int pick(int target){int ans=-1,c=0;for(int i=0;i<a.size();i++)if(a[i]==target&&rand()%++c==0)ans=i;return ans;}};
