#include <vector>
#include <algorithm>
using namespace std;class Solution{public:int maximalSquare(vector<vector<char>>&m){if(m.empty())return 0;vector<int>d(m[0].size()+1);int b=0;for(int i=1;i<=m.size();i++){int p=0;for(int j=1;j<=m[0].size();j++){int old=d[j];if(m[i-1][j-1]=='1'){d[j]=1+min({d[j],d[j-1],p});b=max(b,d[j]);}else d[j]=0;p=old;}}return b*b;}};
