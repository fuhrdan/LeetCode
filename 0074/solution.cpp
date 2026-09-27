#include <vector>
using namespace std;class Solution{public:bool searchMatrix(vector<vector<int>>&m,int t){int R=m.size(),C=m[0].size(),l=0,r=R*C-1;while(l<=r){int x=(l+r)/2,v=m[x/C][x%C];if(v==t)return true;if(v<t)l=x+1;else r=x-1;}return false;}};
