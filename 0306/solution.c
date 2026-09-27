#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
bool isAdditiveNumber(char*s){int n=strlen(s);for(int i=1;i<n;i++){if(s[0]=='0'&&i>1)break;for(int j=i+1;j<n;j++){if(s[i]=='0'&&j-i>1)break;long long a=strtoll(strndup(s,i),0,10),b=strtoll(strndup(s+i,j-i),0,10);int p=j;while(p<n){char buf[64];sprintf(buf,"%lld",a+b);int z=strlen(buf);if(strncmp(s+p,buf,z))break;p+=z;long long c=a+b;a=b;b=c;}if(p==n)return true;}}return false;}
