#include <vector>
using namespace std;class Solution{public:vector<vector<int>> generate(int n){vector<vector<int>>o;for(int i=0;i<n;i++){vector<int>r(i+1,1);for(int j=1;j<i;j++)r[j]=o[i-1][j-1]+o[i-1][j];o.push_back(r);}return o;}};
