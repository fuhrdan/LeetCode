#include <string>
#include <vector>
using namespace std;class Solution{public:bool isValid(string s){vector<char>st;for(char c:s){if(c=='('||c=='['||c=='{')st.push_back(c);else{if(st.empty())return false;char o=st.back();st.pop_back();if((c==')'&&o!='(')||(c==']'&&o!='[')||(c=='}'&&o!='{'))return false;}}return st.empty();}};
