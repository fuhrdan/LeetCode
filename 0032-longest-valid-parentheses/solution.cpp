#include <string>
#include <vector>
#include <algorithm>
using namespace std;class Solution{public:int longestValidParentheses(string s){vector<int>st{-1};int b=0;for(int i=0;i<s.size();i++){if(s[i]=='(')st.push_back(i);else{st.pop_back();if(st.empty())st.push_back(i);else b=max(b,i-st.back());}}return b;}};
