#include <stdlib.h>
#include <stdio.h>
char* getHint(char*s,char*g){int b=0,c=0,a[10]={0},x[10]={0};for(int i=0;s[i];i++)if(s[i]==g[i])b++;else{a[s[i]-'0']++;x[g[i]-'0']++;}for(int i=0;i<10;i++)c+=a[i]<x[i]?a[i]:x[i];char*r=malloc(32);sprintf(r,"%dA%dB",b,c);return r;}
