#include <stdlib.h>
static struct TreeNode*f(int*a,int l,int r){if(l>r)return NULL;int m=(l+r)/2;struct TreeNode*n=malloc(sizeof(*n));n->val=a[m];n->left=f(a,l,m-1);n->right=f(a,m+1,r);return n;}struct TreeNode* sortedArrayToBST(int*a,int n){return f(a,0,n-1);}
