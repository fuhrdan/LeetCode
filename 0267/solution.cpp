#include <vector>
#include <string>
#include <algorithm>
using namespace std;class Solution{vector<string>o;void f(string&h,vector<int>&u,string&c,char mid){if(c.size()==h.size()){string r=c;if(mid)r+=mid;r+=string(c.rbegin(),c.rend());o.push_back(r);return;}for(int i=0;i<h.size();i++){if(u[i]||(i&&h[i]==h[i-1]&&!u[i-1]))continue;u[i]=1;c+=h[i];f(h,u,c,mid);c.pop_back();u[i]=0;}}public:vector<string> generatePalindromes(string s){int cnt[256]{};for(unsigned char c:s)cnt[c]++;int odd=0;char mid=0;string h;for(int i=0;i<256;i++){if(cnt[i]&1)odd++,mid=i;h.append(cnt[i]/2,char(i));}if(odd>1)return{};vector<int>u(h.size());string c;f(h,u,c,mid);return o;}};
