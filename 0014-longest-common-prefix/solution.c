#include <stdlib.h>
#include <string.h>
char* longestCommonPrefix(char** a,int n){if(!n){char*r=malloc(1);r[0]=0;return r;}int len=strlen(a[0]);for(int i=1;i<n;i++){int j=0;while(j<len&&a[i][j]&&a[0][j]==a[i][j])j++;len=j;}char*r=malloc(len+1);memcpy(r,a[0],len);r[len]=0;return r;}
