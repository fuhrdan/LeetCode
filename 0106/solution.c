#include <stdlib.h>
static struct TreeNode*f(int*in,int l,int r,int*post,int*pi){if(l>r)return NULL;int v=post[(*pi)--],k=l;while(in[k]!=v)k++;struct TreeNode*n=malloc(sizeof(*n));n->val=v;n->right=f(in,k+1,r,post,pi);n->left=f(in,l,k-1,post,pi);return n;}struct TreeNode* buildTree(int*in,int is,int*post,int ps){int i=ps-1;return f(in,0,is-1,post,&i);}
