#include <vector>
using namespace std;class NumMatrix{vector<vector<int>>p;public:NumMatrix(vector<vector<int>>&a){int m=a.size(),n=m?a[0].size():0;p.assign(m+1,vector<int>(n+1));for(int i=0;i<m;i++)for(int j=0;j<n;j++)p[i+1][j+1]=a[i][j]+p[i][j+1]+p[i+1][j]-p[i][j];}int sumRegion(int r1,int c1,int r2,int c2){return p[r2+1][c2+1]-p[r1][c2+1]-p[r2+1][c1]+p[r1][c1];}};
