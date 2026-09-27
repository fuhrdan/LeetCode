#include <stdbool.h>
static int h(struct TreeNode*n){if(!n)return 0;int a=h(n->left);if(a<0)return-1;int b=h(n->right);if(b<0)return-1;if(a-b>1||b-a>1)return-1;return 1+(a>b?a:b);}bool isBalanced(struct TreeNode*r){return h(r)>=0;}
