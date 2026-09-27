#include <stdbool.h>
#include <string.h>
bool canWin(char*s){for(int i=0;s[i]&&s[i+1];i++)if(s[i]=='+'&&s[i+1]=='+'){s[i]=s[i+1]='-';bool w=!canWin(s);s[i]=s[i+1]='+';if(w)return true;}return false;}
