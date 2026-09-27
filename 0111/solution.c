int minDepth(struct TreeNode*r){if(!r)return 0;if(!r->left)return 1+minDepth(r->right);if(!r->right)return 1+minDepth(r->left);int a=minDepth(r->left),b=minDepth(r->right);return 1+(a<b?a:b);}
