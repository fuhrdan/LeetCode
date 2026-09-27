#include <string>
#include <vector>
using namespace std;class Solution{public:vector<string> fullJustify(vector<string>&w,int W){vector<string>o;for(int i=0;i<w.size();){int j=i,len=0;while(j<w.size()&&len+w[j].size()+j-i<=W){len+=w[j++].size();}int gaps=j-i-1;string line;if(j==w.size()||gaps==0){for(int k=i;k<j;k++){if(k>i)line+=' ';line+=w[k];}line+=string(W-line.size(),' ');}else{int s=W-len,b=s/gaps,e=s%gaps;for(int k=i;k<j;k++){line+=w[k];if(k<j-1)line+=string(b+(k-i<e),' ');}}o.push_back(line);i=j;}return o;}};
