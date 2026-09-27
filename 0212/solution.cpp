#include <vector>
#include <string>
#include <array>
using namespace std;class Solution{struct N{array<N*,26>c{};string w;};vector<string>o;void dfs(vector<vector<char>>&b,int i,int j,N*p){if(i<0||j<0||i>=b.size()||j>=b[0].size()||b[i][j]=='#')return;p=p->c[b[i][j]-'a'];if(!p)return;if(!p->w.empty()){o.push_back(p->w);p->w.clear();}char c=b[i][j];b[i][j]='#';dfs(b,i+1,j,p);dfs(b,i-1,j,p);dfs(b,i,j+1,p);dfs(b,i,j-1,p);b[i][j]=c;}public:vector<string> findWords(vector<vector<char>>&b,vector<string>&w){N*r=new N;for(auto&s:w){N*p=r;for(char c:s){int k=c-'a';if(!p->c[k])p->c[k]=new N;p=p->c[k];}p->w=s;}for(int i=0;i<b.size();i++)for(int j=0;j<b[0].size();j++)dfs(b,i,j,r);return o;}};
