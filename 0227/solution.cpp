#include <string>
#include <vector>
using namespace std;class Solution{public:int calculate(string s){vector<int>st;int n=0;char op='+';for(int i=0;i<=s.size();i++){char c=i<s.size()?s[i]:0;if(isdigit((unsigned char)c))n=n*10+c-'0';if((!isdigit((unsigned char)c)&&c!=' ')||!c){if(op=='+')st.push_back(n);else if(op=='-')st.push_back(-n);else if(op=='*')st.back()*=n;else st.back()/=n;op=c;n=0;}}int r=0;for(int x:st)r+=x;return r;}};
