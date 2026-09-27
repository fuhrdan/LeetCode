#include <vector>
using namespace std;class NumArray{vector<long long>p;public:NumArray(vector<int>&a):p(a.size()+1){for(int i=0;i<a.size();i++)p[i+1]=p[i]+a[i];}int sumRange(int l,int r){return p[r+1]-p[l];}};
