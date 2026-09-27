#include <string>
#include <vector>
#include <algorithm>
using namespace std;class Solution{public:int lengthLongestPath(string s){vector<int>len(256);int best=0;for(int i=0;i<s.size();){int d=0;while(i<s.size()&&s[i]=='\t')d++,i++;int st=i;bool file=false;while(i<s.size()&&s[i]!='\n'){if(s[i]=='.')file=true;i++;}int n=i-st,total=len[d]+n;if(file)best=max(best,total);else len[d+1]=total+1;if(i<s.size())i++;}return best;}};
