#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;class Solution{bool pal(const string&s,int l,int r){while(l<r)if(s[l++]!=s[r--])return false;return true;}public:vector<vector<int>> palindromePairs(vector<string>&w){unordered_map<string,int>m;for(int i=0;i<w.size();i++)m[w[i]]=i;vector<vector<int>>o;for(int i=0;i<w.size();i++){for(int k=0;k<=w[i].size();k++){if(pal(w[i],0,k-1)){string x=w[i].substr(k);reverse(x.begin(),x.end());if(m.count(x)&&m[x]!=i)o.push_back({m[x],i});}if(k<w[i].size()&&pal(w[i],k,w[i].size()-1)){string x=w[i].substr(0,k);reverse(x.begin(),x.end());if(m.count(x)&&m[x]!=i)o.push_back({i,m[x]});}}}return o;}};
