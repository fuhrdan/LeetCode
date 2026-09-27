#include <stdbool.h>
#include <string.h>
bool isOneEditDistance(char*s,char*t){int m=strlen(s),n=strlen(t);if(m>n)return isOneEditDistance(t,s);if(n-m>1)return false;int i=0;while(i<m&&s[i]==t[i])i++;if(i==m)return n==m+1;if(m==n)i++;while(i<m&&s[i]==t[i+(n-m)])i++;return i==m;}
