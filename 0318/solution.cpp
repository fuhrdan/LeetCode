#include <vector>
#include <string>
#include <algorithm>
using namespace std;class Solution{public:int maxProduct(vector<string>&w){vector<int>m(w.size());for(int i=0;i<w.size();i++)for(char c:w[i])m[i]|=1<<(c-'a');int b=0;for(int i=0;i<w.size();i++)for(int j=i+1;j<w.size();j++)if(!(m[i]&m[j]))b=max(b,(int)(w[i].size()*w[j].size()));return b;}};
