#include <string>
using namespace std;class Solution{public:int firstUniqChar(string s){int c[26]{};for(char x:s)c[x-'a']++;for(int i=0;i<s.size();i++)if(c[s[i]-'a']==1)return i;return-1;}};
