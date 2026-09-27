#include <stdlib.h>
int* majorityElement(int*a,int n,int*rs){int x=0,y=1,cx=0,cy=0;for(int i=0;i<n;i++){if(a[i]==x)cx++;else if(a[i]==y)cy++;else if(!cx){x=a[i];cx=1;}else if(!cy){y=a[i];cy=1;}else{cx--;cy--;}}cx=cy=0;for(int i=0;i<n;i++){if(a[i]==x)cx++;else if(a[i]==y)cy++;}int*r=malloc(2*sizeof(int)),c=0;if(cx>n/3)r[c++]=x;if(cy>n/3)r[c++]=y;*rs=c;return r;}
