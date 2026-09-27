#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
static bool v(char c){return strchr("aeiouAEIOU",c)!=NULL;}char* reverseVowels(char*s){char*r=strdup(s);int l=0,h=strlen(r)-1;while(l<h){while(l<h&&!v(r[l]))l++;while(l<h&&!v(r[h]))h--;char t=r[l];r[l++]=r[h];r[h--]=t;}return r;}
