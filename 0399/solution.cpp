#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
using namespace std;class Solution{unordered_map<string,vector<pair<string,double>>>g;double f(string u,string t,unordered_set<string>&v){if(!g.count(u))return-1; if(u==t)return 1;v.insert(u);for(auto&[x,w]:g[u])if(!v.count(x)){double r=f(x,t,v);if(r>0)return w*r;}return-1;}public:vector<double> calcEquation(vector<vector<string>>&e,vector<double>&val,vector<vector<string>>&q){for(int i=0;i<e.size();i++){g[e[i][0]].push_back({e[i][1],val[i]});g[e[i][1]].push_back({e[i][0],1.0/val[i]});}vector<double>o;for(auto&x:q){unordered_set<string>v;o.push_back(f(x[0],x[1],v));}return o;}};
