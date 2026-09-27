#include <string>
#include <vector>
using namespace std;
class Solution{public:string longestCommonPrefix(vector<string>&a){if(a.empty())return"";string p=a[0];for(int i=1;i<a.size();i++){int j=0;while(j<p.size()&&j<a[i].size()&&p[j]==a[i][j])j++;p.resize(j);}return p;}};
