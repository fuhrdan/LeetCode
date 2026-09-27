#include <string>
#include <vector>
using namespace std;class Solution{vector<string>r;void bt(int n,int o,int c,string&s){if(s.size()==2*n){r.push_back(s);return;}if(o<n){s+='(';bt(n,o+1,c,s);s.pop_back();}if(c<o){s+=')';bt(n,o,c+1,s);s.pop_back();}}public:vector<string> generateParenthesis(int n){string s;bt(n,0,0,s);return r;}};
