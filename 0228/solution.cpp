#include <vector>
#include <string>
using namespace std;class Solution{public:vector<string> summaryRanges(vector<int>&a){vector<string>o;for(int i=0;i<a.size();){int j=i;while(j+1<a.size()&&(long long)a[j+1]==(long long)a[j]+1)j++;o.push_back(i==j?to_string(a[i]):to_string(a[i])+"->"+to_string(a[j]));i=j+1;}return o;}};
