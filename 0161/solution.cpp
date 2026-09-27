#include <string>
using namespace std;class Solution{public:bool isOneEditDistance(string s,string t){if(s.size()>t.size())swap(s,t);if(t.size()-s.size()>1)return false;int i=0;while(i<s.size()&&s[i]==t[i])i++;if(i==s.size())return t.size()==s.size()+1;if(s.size()==t.size())i++;while(i<s.size()&&s[i]==t[i+t.size()-s.size()])i++;return i==s.size();}};
