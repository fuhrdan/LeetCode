#include <vector>
#include <unordered_map>
#include <numeric>
#include <algorithm>
using namespace std;class Solution{public:int maxPoints(vector<vector<int>>&p){int n=p.size(),best=0;for(int i=0;i<n;i++){unordered_map<long long,int>m;int dup=1,local=0;for(int j=i+1;j<n;j++){int dx=p[j][0]-p[i][0],dy=p[j][1]-p[i][1];if(!dx&&!dy){dup++;continue;}int g=gcd(dx,dy);dx/=g;dy/=g;if(dx<0||(dx==0&&dy<0)){dx=-dx;dy=-dy;}long long k=((long long)dx<<32)^(unsigned)dy;local=max(local,++m[k]);}best=max(best,local+dup);}return best;}};
