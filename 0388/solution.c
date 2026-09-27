#include <string.h>
int lengthLongestPath(char*s){int len[256]={0},best=0,i=0;while(s[i]){int d=0;while(s[i]=='\t'){d++;i++;}int start=i,file=0;while(s[i]&&s[i]!='\n'){if(s[i]=='.')file=1;i++;}int name=i-start,total=len[d]+name;if(file){if(total>best)best=total;}else len[d+1]=total+1;if(s[i]=='\n')i++;}return best;}
