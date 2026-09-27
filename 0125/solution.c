#include <stdbool.h>
#include <ctype.h>
#include <string.h>
bool isPalindrome(char*s){int l=0,r=strlen(s)-1;while(l<r){while(l<r&&!isalnum((unsigned char)s[l]))l++;while(l<r&&!isalnum((unsigned char)s[r]))r--;if(tolower((unsigned char)s[l])!=tolower((unsigned char)s[r]))return false;l++;r--;}return true;}
