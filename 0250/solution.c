#include <stdbool.h>
static int cnt;static bool f(struct TreeNode*n){if(!n)return true;bool l=f(n->left),r=f(n->right);if(!l||!r)return false;if(n->left&&n->left->val!=n->val)return false;if(n->right&&n->right->val!=n->val)return false;cnt++;return true;}int countUnivalSubtrees(struct TreeNode*r){cnt=0;f(r);return cnt;}
