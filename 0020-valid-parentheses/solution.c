#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
bool isValid(char*s){int n=strlen(s),top=0;char*st=malloc(n);for(int i=0;i<n;i++){char c=s[i];if(c=='('||c=='['||c=='{')st[top++]=c;else{if(!top){free(st);return false;}char o=st[--top];if((c==')'&&o!='(')||(c==']'&&o!='[')||(c=='}'&&o!='{')){free(st);return false;}}}free(st);return top==0;}
