#include <stdbool.h>
bool isValidSerialization(char*s){int slots=1;for(int i=0;;){if(slots==0)return false;if(s[i]=='#'){slots--;i++;}else{slots++;while(s[i]&&s[i]!=',')i++;}if(!s[i])break;i++;}return slots==0;}
