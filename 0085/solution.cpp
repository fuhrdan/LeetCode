#include <vector>
#include <algorithm>
using namespace std;class Solution{int hist(vector<int>&h){vector<int>st;int b=0;for(int i=0;i<=h.size();i++){int cur=i==h.size()?0:h[i];while(!st.empty()&&h[st.back()]>cur){int ht=h[st.back()];st.pop_back();int l=st.empty()?-1:st.back();b=max(b,ht*(i-l-1));}st.push_back(i);}return b;}public:int maximalRectangle(vector<vector<char>>&m){if(m.empty())return 0;vector<int>h(m[0].size());int b=0;for(auto&r:m){for(int j=0;j<r.size();j++)h[j]=r[j]=='1'?h[j]+1:0;b=max(b,hist(h));}return b;}};
