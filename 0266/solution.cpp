#include <string>
using namespace std;class Solution{public:bool canPermutePalindrome(string s){int c[256]{},odd=0;for(unsigned char x:s){c[x]++;odd+=c[x]&1?1:-1;}return odd<=1;}};
