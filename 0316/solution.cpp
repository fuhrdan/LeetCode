#include <string>
using namespace std;class Solution{public:string removeDuplicateLetters(string s){int last[26]{},used[26]{};for(int i=0;i<s.size();i++)last[s[i]-'a']=i;string r;for(int i=0;i<s.size();i++){int k=s[i]-'a';if(used[k])continue;while(!r.empty()&&r.back()>s[i]&&last[r.back()-'a']>i){used[r.back()-'a']=0;r.pop_back();}r+=s[i];used[k]=1;}return r;}};
