#include <string>
#include <array>
using namespace std;
class Solution {
public:
    string minWindow(string s, string t) {
        array<int,128> need{}; int missing=t.size(), l=0, bestL=0, best=INT_MAX;
        for(char c:t) need[(unsigned char)c]++;
        for(int r=0;r<s.size();r++){
            unsigned char c=s[r]; if(need[c]>0) missing--; need[c]--;
            while(!missing){
                if(r-l+1<best){best=r-l+1;bestL=l;}
                c=s[l++]; need[c]++; if(need[c]>0) missing++;
            }
        }
        return best==INT_MAX?"":s.substr(bestL,best);
    }
};
