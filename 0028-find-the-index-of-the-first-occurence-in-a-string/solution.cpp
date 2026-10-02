#include <string>
using namespace std;class Solution{public:int strStr(string h,string n){auto p=h.find(n);return p==string::npos?-1:(int)p;}};
