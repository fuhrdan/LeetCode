#include <vector>
using namespace std;class Solution{public:bool searchMatrix(vector<vector<int>>&m,int t){if(m.empty())return false;int r=0,c=m[0].size()-1;while(r<m.size()&&c>=0){if(m[r][c]==t)return true;if(m[r][c]>t)c--;else r++;}return false;}};
