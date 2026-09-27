#include <string>
#include <vector>
#include <unordered_map>
using namespace std;class Solution{public:vector<int> findSubstring(string s,vector<string>&w){vector<int>o;if(w.empty())return o;int L=w[0].size(),k=w.size();unordered_map<string,int>need;for(auto&x:w)need[x]++;for(int off=0;off<L;off++){unordered_map<string,int>have;int l=off,c=0;for(int r=off;r+L<=s.size();r+=L){string x=s.substr(r,L);if(!need.count(x)){have.clear();c=0;l=r+L;continue;}have[x]++;c++;while(have[x]>need[x]){have[s.substr(l,L)]--;l+=L;c--;}if(c==k){o.push_back(l);have[s.substr(l,L)]--;l+=L;c--;}}}return o;}};
