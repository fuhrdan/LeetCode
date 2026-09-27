#include <vector>
#include <algorithm>
using namespace std;class Solution{public:vector<vector<int>> insert(vector<vector<int>>&v,vector<int>&x){vector<vector<int>>o;int i=0;while(i<v.size()&&v[i][1]<x[0])o.push_back(v[i++]);while(i<v.size()&&v[i][0]<=x[1]){x[0]=min(x[0],v[i][0]);x[1]=max(x[1],v[i][1]);i++;}o.push_back(x);while(i<v.size())o.push_back(v[i++]);return o;}};
