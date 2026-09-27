#include <string.h>
int strStr(char*h,char*n){int a=strlen(h),b=strlen(n);if(!b)return 0;for(int i=0;i+b<=a;i++){int j=0;while(j<b&&h[i+j]==n[j])j++;if(j==b)return i;}return -1;}
