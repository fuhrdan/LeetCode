#include <vector>
using namespace std;class Solution{public:vector<vector<int>> multiply(vector<vector<int>>&a,vector<vector<int>>&b){int m=a.size(),k=a[0].size(),n=b[0].size();vector<vector<int>>o(m,vector<int>(n));for(int i=0;i<m;i++)for(int x=0;x<k;x++)if(a[i][x])for(int j=0;j<n;j++)if(b[x][j])o[i][j]+=a[i][x]*b[x][j];return o;}};
