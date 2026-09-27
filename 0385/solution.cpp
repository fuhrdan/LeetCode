#include <string>
using namespace std;class Solution{NestedInteger f(string&s,int&i){if(s[i]!='['){int sign=1,v=0;if(s[i]=='-')sign=-1,i++;while(i<s.size()&&isdigit(s[i]))v=v*10+s[i++]-'0';return NestedInteger(sign*v);}NestedInteger r;i++;while(i<s.size()&&s[i]!=']'){r.add(f(s,i));if(i<s.size()&&s[i]==',')i++;}i++;return r;}public:NestedInteger deserialize(string s){int i=0;return f(s,i);}};
