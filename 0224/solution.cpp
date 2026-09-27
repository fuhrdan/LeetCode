#include <string>
#include <vector>
using namespace std;class Solution{public:int calculate(string s){vector<int>st;int r=0,n=0,sg=1;for(int i=0;i<=s.size();i++){char c=i<s.size()?s[i]:0;if(isdigit((unsigned char)c))n=n*10+c-'0';else if(c=='+'||c=='-'){r+=sg*n;n=0;sg=c=='+'?1:-1;}else if(c=='('){st.push_back(r);st.push_back(sg);r=0;sg=1;}else if(c==')'){r+=sg*n;n=0;int x=st.back();st.pop_back();r=x*r+st.back();st.pop_back();}else if(!c){r+=sg*n;}}return r;}};
