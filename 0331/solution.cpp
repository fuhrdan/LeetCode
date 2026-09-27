#include <string>
using namespace std;class Solution{public:bool isValidSerialization(string s){int slots=1;for(int i=0;i<s.size();){if(!slots)return false;if(s[i]=='#'){slots--;i++;}else{slots++;while(i<s.size()&&s[i]!=',')i++;}if(i<s.size()&&s[i]==',')i++;}return slots==0;}};
