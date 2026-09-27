#include <stdbool.h>
bool isAnagram(char*s,char*t){int c[26]={0};for(int i=0;s[i];i++)c[s[i]-'a']++;for(int i=0;t[i];i++)c[t[i]-'a']--;for(int i=0;i<26;i++)if(c[i])return false;return true;}
