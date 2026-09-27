#include <string>
using namespace std;
class Solution {
public:
    string longestPalindrome(string s){
        int n=s.size(),bestL=0,best=1;
        for(int c=0;c<n;c++) for(int t=0;t<2;t++){
            int l=c,r=c+t; while(l>=0&&r<n&&s[l]==s[r]){ if(r-l+1>best){best=r-l+1;bestL=l;} --l;++r; }
        }
        return s.substr(bestL,best);
    }
};
