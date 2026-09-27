#include <stdbool.h>
bool canPermutePalindrome(char*s){int c[256]={0},odd=0;for(int i=0;s[i];i++){c[(unsigned char)s[i]]++;odd+=c[(unsigned char)s[i]]%2?1:-1;}return odd<=1;}
