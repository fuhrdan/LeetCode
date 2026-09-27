#include <stdlib.h>
int calculate(char*s){int*st=malloc(10000*sizeof(int)),top=0,num=0;char op='+';for(int i=0;;i++){char c=s[i];if(c>='0'&&c<='9')num=num*10+c-'0';if(((c<'0'||c>'9')&&c!=' ')||c==0){if(op=='+')st[top++]=num;else if(op=='-')st[top++]=-num;else if(op=='*')st[top-1]*=num;else st[top-1]/=num;op=c;num=0;}if(c==0)break;}int r=0;while(top)r+=st[--top];free(st);return r;}
