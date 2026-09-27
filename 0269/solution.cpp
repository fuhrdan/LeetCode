#include <vector>
#include <string>
#include <queue>
using namespace std;class Solution{public:string alienOrder(vector<string>&w){vector<vector<int>>g(26);int d[26]{},s[26]{};for(auto&x:w)for(char c:x)s[c-'a']=1;for(int i=0;i+1<w.size();i++){int j=0,m=min(w[i].size(),w[i+1].size());while(j<m&&w[i][j]==w[i+1][j])j++;if(j==m){if(w[i].size()>w[i+1].size())return"";}else{int a=w[i][j]-'a',b=w[i+1][j]-'a';bool found=false;for(int v:g[a])if(v==b)found=true;if(!found)g[a].push_back(b),d[b]++;}}queue<int>q;int cnt=0;for(int i=0;i<26;i++)if(s[i]){cnt++;if(!d[i])q.push(i);}string r;while(!q.empty()){int u=q.front();q.pop();r+=char('a'+u);for(int v:g[u])if(--d[v]==0)q.push(v);}return r.size()==cnt?r:"";}};
