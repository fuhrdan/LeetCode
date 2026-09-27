#include <stdlib.h>
static struct TreeNode*f(int*pre,int*pi,int*in,int l,int r){if(l>r)return NULL;int v=pre[(*pi)++],k=l;while(in[k]!=v)k++;struct TreeNode*n=malloc(sizeof(*n));n->val=v;n->left=f(pre,pi,in,l,k-1);n->right=f(pre,pi,in,k+1,r);return n;}struct TreeNode* buildTree(int*pre,int ps,int*in,int is){int i=0;return f(pre,&i,in,0,is-1);}
