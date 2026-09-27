#include <vector>
#include <queue>
using namespace std;class Solution{public:vector<vector<int>> kSmallestPairs(vector<int>&a,vector<int>&b,int k){vector<vector<int>>o;if(a.empty()||b.empty())return o;using T=tuple<long long,int,int>;priority_queue<T,vector<T>,greater<T>>q;for(int i=0;i<a.size()&&i<k;i++)q.push({(long long)a[i]+b[0],i,0});while(k--&&!q.empty()){auto[s,i,j]=q.top();q.pop();o.push_back({a[i],b[j]});if(j+1<b.size())q.push({(long long)a[i]+b[j+1],i,j+1});}return o;}};
