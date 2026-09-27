#include <string>
using namespace std;class Solution{bool v(char c){return string("aeiouAEIOU").find(c)!=string::npos;}public:string reverseVowels(string s){int l=0,r=s.size()-1;while(l<r){while(l<r&&!v(s[l]))l++;while(l<r&&!v(s[r]))r--;swap(s[l++],s[r--]);}return s;}};
