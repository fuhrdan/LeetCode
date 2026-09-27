#include <stdlib.h>
int compareVersion(char*a,char*b){char*p=a,*q=b;while(*p||*q){long x=strtol(p,&p,10),y=strtol(q,&q,10);if(x<y)return-1;if(x>y)return 1;if(*p=='.')p++;if(*q=='.')q++;}return 0;}
