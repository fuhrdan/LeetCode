#include <string>
#include <vector>
#include <algorithm>
using namespace std;class Solution{public:int minCut(string s){int n=s.size();vector<vector<char>>p(n,vector<char>(n));vector<int>d(n+1);d[0]=-1;for(int i=1;i<=n;i++)d[i]=i-1;for(int r=0;r<n;r++)for(int l=r;l>=0;l--)if(s[l]==s[r]&&(r-l<2||p[l+1][r-1])){p[l][r]=1;d[r+1]=min(d[r+1],d[l]+1);}return d[n];}};
