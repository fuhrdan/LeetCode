#include <stdlib.h>
#include <string.h>
int evalRPN(char**t,int n){int*st=malloc(n*sizeof(int)),top=0;for(int i=0;i<n;i++){if(strlen(t[i])==1&&strchr("+-*/",t[i][0])){int b=st[--top],a=st[--top];switch(t[i][0]){case'+':st[top++]=a+b;break;case'-':st[top++]=a-b;break;case'*':st[top++]=a*b;break;default:st[top++]=a/b;}}else st[top++]=atoi(t[i]);}int r=st[0];free(st);return r;}
