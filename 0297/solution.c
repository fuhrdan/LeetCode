#include <stdlib.h>
#include <stdio.h>
#include <string.h>
static void ser(struct TreeNode*n,char*b,int*p){if(!n){*p+=sprintf(b+*p,"# ");return;}*p+=sprintf(b+*p,"%d ",n->val);ser(n->left,b,p);ser(n->right,b,p);}char* serialize(struct TreeNode*r){char*b=malloc(200000);int p=0;ser(r,b,&p);b[p]=0;return b;}static struct TreeNode*des(char**s){while(**s==' ')(*s)++;if(**s=='#'){(*s)++;return NULL;}char*e;int v=strtol(*s,&e,10);*s=e;struct TreeNode*n=malloc(sizeof(*n));n->val=v;n->left=des(s);n->right=des(s);return n;}struct TreeNode* deserialize(char*data){char*p=data;return des(&p);}
