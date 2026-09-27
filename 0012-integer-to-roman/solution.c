#include <stdlib.h>
char* intToRoman(int num){int v[]={1000,900,500,400,100,90,50,40,10,9,5,4,1};char*s[]={"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};char*out=malloc(32);int k=0;for(int i=0;i<13;i++)while(num>=v[i]){num-=v[i];for(char*p=s[i];*p;p++)out[k++]=*p;}out[k]=0;return out;}
