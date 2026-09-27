#include <vector>
#include <algorithm>
using namespace std;class Solution{public:int maxCoins(vector<int>&a){int n=a.size();vector<int>m(n+2,1);for(int i=0;i<n;i++)m[i+1]=a[i];vector<vector<int>>d(n+2,vector<int>(n+2));for(int len=1;len<=n;len++)for(int l=1;l+len-1<=n;l++){int r=l+len-1;for(int k=l;k<=r;k++)d[l][r]=max(d[l][r],d[l][k-1]+m[l-1]*m[k]*m[r+1]+d[k+1][r]);}return d[1][n];}};
