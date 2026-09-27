#include <string>
#include <sstream>
#include <vector>
using namespace std;class Solution{public:string reverseWords(string s){stringstream ss(s);vector<string>w;string x;while(ss>>x)w.push_back(x);string r;for(int i=w.size()-1;i>=0;i--){if(!r.empty())r+=' ';r+=w[i];}return r;}};
