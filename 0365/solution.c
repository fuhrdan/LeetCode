#include <stdbool.h>
static int g(int a,int b){while(b){int t=a%b;a=b;b=t;}return a;}bool canMeasureWater(int x,int y,int z){if(z==0)return true;if((long long)x+y<z)return false;return z%g(x,y)==0;}
