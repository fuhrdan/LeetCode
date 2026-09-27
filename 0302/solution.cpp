#include <vector>
#include <algorithm>
using namespace std;class Solution{public:int minArea(vector<vector<char>>&a,int x,int y){int m=a.size(),n=a[0].size(),r1=m,r2=-1,c1=n,c2=-1;for(int i=0;i<m;i++)for(int j=0;j<n;j++)if(a[i][j]=='1'){r1=min(r1,i);r2=max(r2,i);c1=min(c1,j);c2=max(c2,j);}return(r2-r1+1)*(c2-c1+1);}};
