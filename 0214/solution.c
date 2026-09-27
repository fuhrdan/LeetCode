#include <stdlib.h>
#include <string.h>
char* shortestPalindrome(char*s){int n=strlen(s),m=2*n+1;char*t=malloc(m+1);memcpy(t,s,n);t[n]='#';for(int i=0;i<n;i++)t[n+1+i]=s[n-1-i];t[m]=0;int*pi=calloc(m,sizeof(int));for(int i=1;i<m;i++){int j=pi[i-1];while(j>0&&t[i]!=t[j])j=pi[j-1];if(t[i]==t[j])j++;pi[i]=j;}int keep=pi[m-1],add=n-keep;char*r=malloc(n+add+1);for(int i=0;i<add;i++)r[i]=s[n-1-i];memcpy(r+add,s,n+1);free(t);free(pi);return r;}
