#include <vector>
#include <string>
#include <unordered_map>
#include <queue>
using namespace std;class Solution{unordered_map<string,priority_queue<string,vector<string>,greater<string>>>g;vector<string>o;void f(string u){auto&q=g[u];while(!q.empty()){string v=q.top();q.pop();f(v);}o.push_back(u);}public:vector<string> findItinerary(vector<vector<string>>&t){for(auto&x:t)g[x[0]].push(x[1]);f("JFK");reverse(o.begin(),o.end());return o;}};
