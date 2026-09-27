#include <string>
#include <vector>
using namespace std;class Solution{public:int evalRPN(vector<string>&t){vector<int>st;for(auto&s:t){if(s.size()==1&&string("+-*/").find(s[0])!=string::npos){int b=st.back();st.pop_back();int a=st.back();st.pop_back();if(s=="+")st.push_back(a+b);else if(s=="-")st.push_back(a-b);else if(s=="*")st.push_back(a*b);else st.push_back(a/b);}else st.push_back(stoi(s));}return st.back();}};
