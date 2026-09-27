#include <stdlib.h>
#include <string.h>
char* removeDuplicateLetters(char*s){int last[26],used[26]={0},n=strlen(s),top=0;for(int i=0;i<n;i++)last[s[i]-'a']=i;char*r=malloc(n+1);for(int i=0;i<n;i++){int k=s[i]-'a';if(used[k])continue;while(top&&r[top-1]>s[i]&&last[r[top-1]-'a']>i)used[r[--top]-'a']=0;r[top++]=s[i];used[k]=1;}r[top]=0;return r;}
