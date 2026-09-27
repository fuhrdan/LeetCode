#include <vector>
#include <algorithm>
using namespace std;class Solution{public:void rotate(vector<vector<int>>&m){int n=m.size();for(int i=0;i<n;i++)for(int j=i+1;j<n;j++)swap(m[i][j],m[j][i]);for(auto&r:m)reverse(r.begin(),r.end());}};
