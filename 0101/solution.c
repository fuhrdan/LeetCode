#include <stdbool.h>
static bool mir(struct TreeNode*a,struct TreeNode*b){if(!a||!b)return a==b;return a->val==b->val&&mir(a->left,b->right)&&mir(a->right,b->left);}bool isSymmetric(struct TreeNode*root){return !root||mir(root->left,root->right);}
