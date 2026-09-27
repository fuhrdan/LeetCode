#include <vector>
#include <string>
using namespace std;class Solution{bool f(vector<vector<char>>&b,int i,int j,string&w,int k){if(k==w.size())return true;if(i<0||j<0||i>=b.size()||j>=b[0].size()||b[i][j]!=w[k])return false;char c=b[i][j];b[i][j]=0;bool ok=f(b,i+1,j,w,k+1)||f(b,i-1,j,w,k+1)||f(b,i,j+1,w,k+1)||f(b,i,j-1,w,k+1);b[i][j]=c;return ok;}public:bool exist(vector<vector<char>>&b,string w){for(int i=0;i<b.size();i++)for(int j=0;j<b[0].size();j++)if(f(b,i,j,w,0))return true;return false;}};
