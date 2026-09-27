#include <vector>
using namespace std;class NumArray{int n;vector<int>b,a;void add(int i,int d){for(i++;i<=n;i+=i&-i)b[i]+=d;}int sum(int i){int r=0;for(i++;i;i-=i&-i)r+=b[i];return r;}public:NumArray(vector<int>&x):n(x.size()),b(n+1),a(x){for(int i=0;i<n;i++)add(i,a[i]);}void update(int i,int v){int d=v-a[i];a[i]=v;add(i,d);}int sumRange(int l,int r){return sum(r)-(l?sum(l-1):0);}};
