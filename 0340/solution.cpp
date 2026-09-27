#include <string>
#include <algorithm>
using namespace std;class Solution{public:int lengthOfLongestSubstringKDistinct(string s,int k){if(!k)return 0;int c[256]{},d=0,l=0,b=0;for(int r=0;r<s.size();r++){unsigned char x=s[r];if(c[x]++==0)d++;while(d>k){unsigned char y=s[l++];if(--c[y]==0)d--;}b=max(b,r-l+1);}return b;}};
