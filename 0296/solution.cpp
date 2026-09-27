#include <vector>
#include <cstdlib>
using namespace std;class Solution{public:int minTotalDistance(vector<vector<int>>&g){vector<int>r,c;for(int i=0;i<g.size();i++)for(int j=0;j<g[0].size();j++)if(g[i][j])r.push_back(i);for(int j=0;j<g[0].size();j++)for(int i=0;i<g.size();i++)if(g[i][j])c.push_back(j);int mr=r[r.size()/2],mc=c[c.size()/2],s=0;for(int x:r)s+=abs(x-mr);for(int x:c)s+=abs(x-mc);return s;}};
