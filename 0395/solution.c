#include <string.h>
static int f(char*s,int l,int r,int k){if(r-l<k)return 0;int c[26]={0};for(int i=l;i<r;i++)c[s[i]-'a']++;for(int i=l;i<r;i++)if(c[s[i]-'a']<k){int j=i+1;while(j<r&&c[s[j]-'a']<k)j++;int a=f(s,l,i,k),b=f(s,j,r,k);return a>b?a:b;}return r-l;}int longestSubstring(char*s,int k){return f(s,0,strlen(s),k);}
