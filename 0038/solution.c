#include <stdlib.h>
#include <string.h>
char* countAndSay(int n){char*s=malloc(2);s[0]='1';s[1]=0;for(int k=1;k<n;k++){int len=strlen(s),cap=len*3+1,p=0;char*t=malloc(cap);for(int i=0;i<len;){int j=i;while(j<len&&s[j]==s[i])j++;p+=sprintf(t+p,"%d%c",j-i,s[i]);i=j;}free(s);s=t;}return s;}
