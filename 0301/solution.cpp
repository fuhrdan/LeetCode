#include <string>
#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;class Solution{bool ok(const string&s){int b=0;for(char c:s){if(c=='(')b++;else if(c==')'&&--b<0)return false;}return b==0;}public:vector<string> removeInvalidParentheses(string s){vector<string>o;queue<string>q;q.push(s);unordered_set<string>v{s};bool found=false;while(!q.empty()&&!found){int z=q.size();while(z--){string x=q.front();q.pop();if(ok(x)){o.push_back(x);found=true;}if(found)continue;for(int i=0;i<x.size();i++)if(x[i]=='('||x[i]==')'){string y=x.substr(0,i)+x.substr(i+1);if(v.insert(y).second)q.push(y);}}}return o;}};
