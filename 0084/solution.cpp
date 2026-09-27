#include <vector>
#include <algorithm>
using namespace std;class Solution{public:int largestRectangleArea(vector<int>&h){vector<int>st;int b=0;for(int i=0;i<=h.size();i++){int cur=i==h.size()?0:h[i];while(!st.empty()&&h[st.back()]>cur){int ht=h[st.back()];st.pop_back();int l=st.empty()?-1:st.back();b=max(b,ht*(i-l-1));}st.push_back(i);}return b;}};
