#include <vector>
using namespace std;class Solution{public:vector<int> getModifiedArray(int n,vector<vector<int>>&u){vector<int>r(n);for(auto&x:u){r[x[0]]+=x[2];if(x[1]+1<n)r[x[1]+1]-=x[2];}for(int i=1;i<n;i++)r[i]+=r[i-1];return r;}};
