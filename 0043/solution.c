#include <stdlib.h>
#include <string.h>
char* multiply(char*a,char*b){if(a[0]=='0'||b[0]=='0'){char*r=malloc(2);r[0]='0';r[1]=0;return r;}int m=strlen(a),n=strlen(b),*d=calloc(m+n,sizeof(int));for(int i=m-1;i>=0;i--)for(int j=n-1;j>=0;j--){int p=(a[i]-'0')*(b[j]-'0')+d[i+j+1];d[i+j+1]=p%10;d[i+j]+=p/10;}int k=d[0]==0,rlen=m+n-k;char*r=malloc(rlen+1);for(int i=0;i<rlen;i++)r[i]='0'+d[i+k];r[rlen]=0;free(d);return r;}
