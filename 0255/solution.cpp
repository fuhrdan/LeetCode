#include <vector>
#include <climits>
using namespace std;class Solution{public:bool verifyPreorder(vector<int>&a){vector<int>st;int low=INT_MIN;for(int x:a){if(x<low)return false;while(!st.empty()&&x>st.back()){low=st.back();st.pop_back();}st.push_back(x);}return true;}};
