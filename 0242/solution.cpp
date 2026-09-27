#include <string>
using namespace std;class Solution{public:bool isAnagram(string s,string t){int c[26]{};for(char x:s)c[x-'a']++;for(char x:t)c[x-'a']--;for(int x:c)if(x)return false;return true;}};
