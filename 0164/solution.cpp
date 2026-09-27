#include <vector>
#include <climits>
#include <algorithm>
using namespace std;class Solution{public:int maximumGap(vector<int>&a){int n=a.size();if(n<2)return 0;auto [mi,ma]=minmax_element(a.begin(),a.end());int mn=*mi,mx=*ma;if(mn==mx)return 0;int sz=(mx-mn+n-2)/(n-1),bc=(mx-mn)/sz+1;vector<int>lo(bc,INT_MAX),hi(bc,INT_MIN);vector<char>u(bc);for(int x:a){int k=(x-mn)/sz;u[k]=1;lo[k]=min(lo[k],x);hi[k]=max(hi[k],x);}int p=mn,b=0;for(int i=0;i<bc;i++)if(u[i]){b=max(b,lo[i]-p);p=hi[i];}return b;}};
