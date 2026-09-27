#include <vector>
#include <algorithm>
using namespace std;class Solution{public:int maxRotateFunction(vector<int>&a){long long sum=0,f=0;for(int i=0;i<a.size();i++){sum+=a[i];f+=1LL*i*a[i];}long long b=f;for(int k=1;k<a.size();k++){f+=sum-1LL*a.size()*a[a.size()-k];b=max(b,f);}return b;}};
