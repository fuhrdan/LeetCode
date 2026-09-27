#include <stdbool.h>
bool hasPathSum(struct TreeNode*r,int t){if(!r)return false;if(!r->left&&!r->right)return r->val==t;return hasPathSum(r->left,t-r->val)||hasPathSum(r->right,t-r->val);}
