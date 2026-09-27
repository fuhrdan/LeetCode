#include <string>
#include <algorithm>
using namespace std;class Solution{int f(string&s,int l,int r,int k){if(r-l<k)return 0;int c[26]{};for(int i=l;i<r;i++)c[s[i]-'a']++;for(int i=l;i<r;i++)if(c[s[i]-'a']<k){int j=i+1;while(j<r&&c[s[j]-'a']<k)j++;return max(f(s,l,i,k),f(s,j,r,k));}return r-l;}public:int longestSubstring(string s,int k){return f(s,0,s.size(),k);}};
