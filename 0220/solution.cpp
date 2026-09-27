#include <vector>
#include <unordered_map>
#include <cstdlib>
using namespace std;class Solution{public:bool containsNearbyAlmostDuplicate(vector<int>&a,int k,int t){if(t<0)return false;long long w=(long long)t+1;unordered_map<long long,long long>m;auto id=[&](long long x){return x>=0?x/w:(x+1)/w-1;};for(int i=0;i<a.size();i++){long long x=a[i],b=id(x);if(m.count(b)||m.count(b-1)&&llabs(x-m[b-1])<=t||m.count(b+1)&&llabs(x-m[b+1])<=t)return true;m[b]=x;if(i>=k)m.erase(id(a[i-k]));}return false;}};
