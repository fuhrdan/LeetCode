#include <string>
#include <vector>
using namespace std;class Solution{vector<string>o;string map[10]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};void bt(string&d,int i,string&cur){if(i==d.size()){o.push_back(cur);return;}for(char c:map[d[i]-'0']){cur+=c;bt(d,i+1,cur);cur.pop_back();}}public:vector<string> letterCombinations(string d){if(d.empty())return{};string c;bt(d,0,c);return o;}};
