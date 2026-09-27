#include <string>
#include <vector>
using namespace std;class Solution{public:bool wordBreak(string s,vector<string>&w){vector<char>d(s.size()+1);d[0]=1;for(int i=1;i<=s.size();i++)for(auto&x:w)if(x.size()<=i&&d[i-x.size()]&&s.compare(i-x.size(),x.size(),x)==0){d[i]=1;break;}return d.back();}};
