#include <stdbool.h>
bool validUtf8(int*a,int n){int need=0;for(int i=0;i<n;i++){int b=a[i]&255;if(need){if((b>>6)!=2)return false;need--;}else if((b>>7)==0)continue;else if((b>>5)==6)need=1;else if((b>>4)==14)need=2;else if((b>>3)==30)need=3;else return false;}return need==0;}
