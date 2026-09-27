#include <string>
#include <vector>
using namespace std;class Solution{public:string getPermutation(int n,int k){vector<int>v;int f=1;for(int i=1;i<=n;i++){v.push_back(i);f*=i;}string s;k--;for(int rem=n;rem;rem--){f/=rem;int idx=k/f;k%=f;s+=char('0'+v[idx]);v.erase(v.begin()+idx);}return s;}};
