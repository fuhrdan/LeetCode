#include <string>
#include <unordered_map>
using namespace std;class Solution{unordered_map<string,bool>m;public:bool canWin(string s){if(m.count(s))return m[s];for(int i=0;i+1<s.size();i++)if(s[i]=='+'&&s[i+1]=='+'){s[i]=s[i+1]='-';bool w=!canWin(s);s[i]=s[i+1]='+';if(w)return m[s]=true;}return m[s]=false;}};
