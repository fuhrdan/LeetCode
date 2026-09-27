#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <queue>
using namespace std;class Solution{unordered_map<string,vector<string>>pre;vector<vector<string>>o;void dfs(string w,string b,vector<string>&p){p.push_back(w);if(w==b){o.emplace_back(p.rbegin(),p.rend());}else for(auto&x:pre[w])dfs(x,b,p);p.pop_back();}public:vector<vector<string>> findLadders(string b,string e,vector<string>&wl){unordered_set<string>dict(wl.begin(),wl.end());if(!dict.count(e))return{};queue<string>q;q.push(b);unordered_map<string,int>d{{b,0}};while(!q.empty()){string w=q.front();q.pop();int nd=d[w]+1;string x=w;for(int i=0;i<x.size();i++){char old=x[i];for(char c='a';c<='z';c++){x[i]=c;if(dict.count(x)){if(!d.count(x)){d[x]=nd;q.push(x);}if(d[x]==nd)pre[x].push_back(w);}}x[i]=old;}}if(d.count(e)){vector<string>p;dfs(e,b,p);}return o;}};
