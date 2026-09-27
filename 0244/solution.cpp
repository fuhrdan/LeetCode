#include <unordered_map>
#include <vector>
#include <string>
#include <climits>
using namespace std;class WordDistance{unordered_map<string,vector<int>>m;public:WordDistance(vector<string>&w){for(int i=0;i<w.size();i++)m[w[i]].push_back(i);}int shortest(string a,string b){auto&x=m[a];auto&y=m[b];int i=0,j=0,r=INT_MAX;while(i<x.size()&&j<y.size()){r=min(r,abs(x[i]-y[j]));if(x[i]<y[j])i++;else j++;}return r;}};
