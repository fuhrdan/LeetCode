#include <vector>
using namespace std;class Solution{public:int kthSmallest(vector<vector<int>>&m,int k){int n=m.size(),lo=m[0][0],hi=m[n-1][n-1];while(lo<hi){int mid=lo+(hi-lo)/2,c=0,j=n-1;for(int i=0;i<n;i++){while(j>=0&&m[i][j]>mid)j--;c+=j+1;}if(c<k)lo=mid+1;else hi=mid;}return lo;}};
