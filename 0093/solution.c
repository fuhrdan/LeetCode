#include <stdlib.h>
#include <string.h>
#include <stdio.h>
static void f(char*s,int n,int pos,int part,int seg[4],char***o,int*c,int*cap){if(part==4){if(pos!=n)return;if(*c==*cap){*cap*=2;*o=realloc(*o,*cap*sizeof(char*));}char*b=malloc(16);sprintf(b,"%d.%d.%d.%d",seg[0],seg[1],seg[2],seg[3]);(*o)[(*c)++]=b;return;}int v=0;for(int len=1;len<=3&&pos+len<=n;len++){if(len>1&&s[pos]=='0')break;v=v*10+s[pos+len-1]-'0';if(v>255)break;seg[part]=v;f(s,n,pos+len,part+1,seg,o,c,cap);}}char** restoreIpAddresses(char*s,int*rs){int cap=16,c=0,seg[4];char**o=malloc(cap*sizeof(char*));f(s,strlen(s),0,0,seg,&o,&c,&cap);*rs=c;return o;}
