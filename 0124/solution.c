#include <limits.h>
static int best;static int f(struct TreeNode*n){if(!n)return 0;int l=f(n->left),r=f(n->right);if(l<0)l=0;if(r<0)r=0;if(n->val+l+r>best)best=n->val+l+r;return n->val+(l>r?l:r);}int maxPathSum(struct TreeNode*r){best=INT_MIN;f(r);return best;}
