#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;class Solution{public:int maxSubArrayLen(vector<int>&a,int k){unordered_map<long long,int>m{{0,-1}};long long s=0;int b=0;for(int i=0;i<a.size();i++){s+=a[i];if(m.count(s-k))b=max(b,i-m[s-k]);if(!m.count(s))m[s]=i;}return b;}};
