#include <string.h>
int lengthOfLastWord(char*s){int i=strlen(s)-1;while(i>=0&&s[i]==' ')i--;int e=i;while(i>=0&&s[i]!=' ')i--;return e-i;}
