#include <string>
#include <queue>
#include <vector>
using namespace std;class Solution{public:string rearrangeString(string s,int k){if(k<=1)return s;int c[26]{};for(char x:s)c[x-'a']++;priority_queue<pair<int,char>>pq;for(int i=0;i<26;i++)if(c[i])pq.push({c[i],char('a'+i)});queue<pair<int,pair<int,char>>>wait;string o;for(int i=0;i<s.size();i++){while(!wait.empty()&&wait.front().first<=i){pq.push(wait.front().second);wait.pop();}if(pq.empty())return"";auto [cnt,ch]=pq.top();pq.pop();o+=ch;if(--cnt)wait.push({i+k,{cnt,ch}});}return o;}};
