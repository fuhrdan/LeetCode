#include <vector>
#include <unordered_map>
using namespace std;class Solution{public:vector<int> intersect(vector<int>&a,vector<int>&b){unordered_map<int,int>m;for(int x:a)m[x]++;vector<int>o;for(int x:b)if(m[x]>0){o.push_back(x);m[x]--;}return o;}};
