#include <vector>
#include <algorithm>
using namespace std;class Solution{public:int minimumTotal(vector<vector<int>>&t){vector<int>d=t.back();for(int i=t.size()-2;i>=0;i--)for(int j=0;j<=i;j++)d[j]=t[i][j]+min(d[j],d[j+1]);return d[0];}};
