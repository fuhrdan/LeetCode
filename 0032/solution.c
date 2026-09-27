#include <stdlib.h>
#include <string.h>
int longestValidParentheses(char*s){int n=strlen(s),*st=malloc((n+1)*sizeof(int)),top=0,b=0;st[0]=-1;for(int i=0;i<n;i++){if(s[i]=='(')st[++top]=i;else{top--;if(top<0){top=0;st[0]=i;}else{int x=i-st[top];if(x>b)b=x;}}}free(st);return b;}
