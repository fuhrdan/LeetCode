#include <vector>
#include <string>
#include <climits>
using namespace std;class Solution{public:int shortestWordDistance(vector<string>&w,string a,string b){int r=INT_MAX;if(a==b){int p=-1;for(int i=0;i<w.size();i++)if(w[i]==a){if(p>=0)r=min(r,i-p);p=i;}return r;}int x=-1,y=-1;for(int i=0;i<w.size();i++){if(w[i]==a)x=i;if(w[i]==b)y=i;if(x>=0&&y>=0)r=min(r,abs(x-y));}return r;}};
