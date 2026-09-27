#include <string>
using namespace std;class Solution{public:int titleToNumber(string s){int r=0;for(char c:s)r=r*26+c-'A'+1;return r;}};
