#include <vector>
#include <string>
#include <climits>
#include <algorithm>
using namespace std;class Solution{public:int shortestDistance(vector<string>&w,string a,string b){int x=-1,y=-1,r=INT_MAX;for(int i=0;i<w.size();i++){if(w[i]==a)x=i;if(w[i]==b)y=i;if(x>=0&&y>=0)r=min(r,abs(x-y));}return r;}};
