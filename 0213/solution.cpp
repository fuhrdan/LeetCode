#include <vector>
#include <algorithm>
using namespace std;class Solution{int f(vector<int>&a,int l,int r){int p2=0,p1=0;for(int i=l;i<=r;i++){int c=max(p1,p2+a[i]);p2=p1;p1=c;}return p1;}public:int rob(vector<int>&a){if(a.size()==1)return a[0];return max(f(a,0,a.size()-2),f(a,1,a.size()-1));}};
