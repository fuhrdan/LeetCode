#include <string>
#include <stack>
using namespace std;class Solution{public:string decodeString(string s){stack<int>nums;stack<string>prev;string cur;int n=0;for(char c:s){if(isdigit(c))n=n*10+c-'0';else if(c=='['){nums.push(n);prev.push(cur);n=0;cur.clear();}else if(c==']'){string x=cur;cur=prev.top();prev.pop();int k=nums.top();nums.pop();while(k--)cur+=x;}else cur+=c;}return cur;}};
