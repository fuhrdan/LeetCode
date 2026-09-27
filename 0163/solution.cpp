#include <string>
#include <vector>
using namespace std;class Solution{string f(long long a,long long b){return a==b?to_string(a):to_string(a)+"->"+to_string(b);}public:vector<string> findMissingRanges(vector<int>&a,int lo,int hi){vector<string>o;long long p=(long long)lo-1;for(int i=0;i<=a.size();i++){long long c=i<a.size()?a[i]:(long long)hi+1;if(c-p>=2)o.push_back(f(p+1,c-1));p=c;}return o;}};
