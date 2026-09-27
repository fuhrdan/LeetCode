#include <stdbool.h>
bool canConstruct(char*r,char*m){int c[26]={0};for(int i=0;m[i];i++)c[m[i]-'a']++;for(int i=0;r[i];i++)if(--c[r[i]-'a']<0)return false;return true;}
