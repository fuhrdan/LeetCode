#include <vector>
#include <climits>
#include <algorithm>
using namespace std;class Solution{public:int minCostII(vector<vector<int>>&c){if(c.empty())return 0;vector<int>d=c[0];for(int i=1;i<c.size();i++){int m1=INT_MAX,m2=INT_MAX,id=-1;for(int j=0;j<d.size();j++)if(d[j]<m1){m2=m1;m1=d[j];id=j;}else if(d[j]<m2)m2=d[j];for(int j=0;j<d.size();j++)d[j]=c[i][j]+(j==id?m2:m1);}return *min_element(d.begin(),d.end());}};
