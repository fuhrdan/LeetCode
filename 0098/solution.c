#include <stdbool.h>
#include <limits.h>
static bool f(struct TreeNode*n,long long lo,long long hi){if(!n)return true;if(n->val<=lo||n->val>=hi)return false;return f(n->left,lo,n->val)&&f(n->right,n->val,hi);}bool isValidBST(struct TreeNode*root){return f(root,LLONG_MIN,LLONG_MAX);}
