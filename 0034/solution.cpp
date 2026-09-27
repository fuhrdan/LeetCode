#include <vector>
#include <algorithm>
using namespace std;class Solution{public:vector<int> searchRange(vector<int>&a,int t){auto l=lower_bound(a.begin(),a.end(),t),r=upper_bound(a.begin(),a.end(),t);if(l==a.end()||*l!=t)return{-1,-1};return{(int)(l-a.begin()),(int)(r-a.begin()-1)};}};
