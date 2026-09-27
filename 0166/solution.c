#include <stdlib.h>
#include <stdio.h>
#include <string.h>
typedef struct{long long rem;int pos;}E;
char* fractionToDecimal(int num,int den){if(!num)return strdup("0");char*r=malloc(20000);int p=0;long long a=num,b=den;if((a<0)^(b<0))r[p++]='-';if(a<0)a=-a;if(b<0)b=-b;p+=sprintf(r+p,"%lld",a/b);long long rem=a%b;if(!rem){r[p]=0;return r;}r[p++]='.';E*seen=malloc(10000*sizeof(E));int c=0;while(rem){int found=-1;for(int i=0;i<c;i++)if(seen[i].rem==rem){found=i;break;}if(found>=0){int pos=seen[found].pos;memmove(r+pos+1,r+pos,p-pos);r[pos]='(';p++;r[p++]=')';break;}seen[c++]=(E){rem,p};rem*=10;r[p++]='0'+rem/b;rem%=b;}r[p]=0;free(seen);return r;}
