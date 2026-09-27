#include <string>
#include <array>
#include <algorithm>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        array<int,256> last; last.fill(-1); int left=0,best=0;
        for(int r=0;r<(int)s.size();++r){ unsigned char c=s[r]; left=max(left,last[c]+1); last[c]=r; best=max(best,r-left+1); }
        return best;
    }
};
