#include <stdlib.h>
#include <stdio.h>
#include <string.h>
static void f(struct TreeNode*n,char*buf,char***o,int*c,int*cap){int len=strlen(buf),w=sprintf(buf+len,len?"->%d":"%d",n->val);if(!n->left&&!n->right){if(*c==*cap){*cap*=2;*o=realloc(*o,*cap*sizeof(char*));}(*o)[(*c)++]=strdup(buf);}else{if(n->left)f(n->left,buf,o,c,cap);buf[len]=0;if(n->right)f(n->right,buf,o,c,cap);}buf[len]=0;}char** binaryTreePaths(struct TreeNode*r,int*rs){int cap=16,c=0;char**o=malloc(cap*sizeof(char*));if(r){char b[4096]={0};f(r,b,&o,&c,&cap);}*rs=c;return o;}
