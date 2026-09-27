#include <string>
#include <array>
#include <algorithm>
using namespace std;class Solution{public:int lengthOfLongestSubstringTwoDistinct(string s){array<int,256>c{};int l=0,d=0,b=0;for(int r=0;r<s.size();r++){if(c[(unsigned char)s[r]]++==0)d++;while(d>2)if(--c[(unsigned char)s[l++]]==0)d--;b=max(b,r-l+1);}return b;}};
