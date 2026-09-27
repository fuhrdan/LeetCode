#include <stdbool.h>
bool isSubsequence(char*s,char*t){int i=0;for(int j=0;t[j]&&s[i];j++)if(s[i]==t[j])i++;return s[i]==0;}
