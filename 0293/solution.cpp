#include <vector>
#include <string>
using namespace std;class Solution{public:vector<string> generatePossibleNextMoves(string s){vector<string>o;for(int i=0;i+1<s.size();i++)if(s[i]=='+'&&s[i+1]=='+'){string x=s;x[i]=x[i+1]='-';o.push_back(x);}return o;}};
