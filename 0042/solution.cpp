#include <vector>
#include <algorithm>
using namespace std;class Solution{public:int trap(vector<int>&h){int l=0,r=h.size()-1,lm=0,rm=0,w=0;while(l<r){if(h[l]<h[r]){lm=max(lm,h[l]);w+=lm-h[l++];}else{rm=max(rm,h[r]);w+=rm-h[r--];}}return w;}};
