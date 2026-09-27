#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
static signed char memo[31][31][31];
static bool f(char*a,char*b,int i,int j,int n){if(memo[i][j][n])return memo[i][j][n]>0;int cnt[26]={0};for(int k=0;k<n;k++){cnt[a[i+k]-'a']++;cnt[b[j+k]-'a']--;}for(int k=0;k<26;k++)if(cnt[k]){memo[i][j][n]=-1;return false;}if(strncmp(a+i,b+j,n)==0){memo[i][j][n]=1;return true;}for(int k=1;k<n;k++)if((f(a,b,i,j,k)&&f(a,b,i+k,j+k,n-k))||(f(a,b,i,j+n-k,k)&&f(a,b,i+k,j,n-k))){memo[i][j][n]=1;return true;}memo[i][j][n]=-1;return false;}bool isScramble(char*s1,char*s2){memset(memo,0,sizeof(memo));int n=strlen(s1);return strlen(s2)==n&&f(s1,s2,0,0,n);}
