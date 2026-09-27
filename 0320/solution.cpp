#include <vector>
#include <string>
using namespace std;class Solution{vector<string>o;void f(string&w,int i,int cnt,string s){if(i==w.size()){if(cnt)s+=to_string(cnt);o.push_back(s);return;}f(w,i+1,cnt+1,s);if(cnt)s+=to_string(cnt);f(w,i+1,0,s+w[i]);}public:vector<string> generateAbbreviations(string w){f(w,0,0,"");return o;}};
