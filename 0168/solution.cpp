#include <string>
#include <algorithm>
using namespace std;class Solution{public:string convertToTitle(int n){string s;while(n){n--;s+=char('A'+n%26);n/=26;}reverse(s.begin(),s.end());return s;}};
