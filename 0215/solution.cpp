#include <vector>
using namespace std;class Solution{int part(vector<int>&a,int l,int r){int p=a[r],i=l;for(int j=l;j<r;j++)if(a[j]<=p)swap(a[i++],a[j]);swap(a[i],a[r]);return i;}public:int findKthLargest(vector<int>&a,int k){int t=a.size()-k,l=0,r=a.size()-1;for(;;){int p=part(a,l,r);if(p==t)return a[p];if(p<t)l=p+1;else r=p-1;}}};
