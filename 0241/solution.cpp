#include <string>
#include <vector>
using namespace std;class Solution{public:vector<int> diffWaysToCompute(string s){vector<int>o;for(int i=0;i<s.size();i++)if(!isdigit((unsigned char)s[i])){auto a=diffWaysToCompute(s.substr(0,i)),b=diffWaysToCompute(s.substr(i+1));for(int x:a)for(int y:b)o.push_back(s[i]=='+'?x+y:s[i]=='-'?x-y:x*y);}if(o.empty())o.push_back(stoi(s));return o;}};
