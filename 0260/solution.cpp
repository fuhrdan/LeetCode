#include <vector>
using namespace std;class Solution{public:vector<int> singleNumber(vector<int>&a){int x=0;for(int v:a)x^=v;unsigned b=(unsigned)x&-(unsigned)x;int p=0,q=0;for(int v:a)((unsigned)v&b?p:q)^=v;return{p,q};}};
