struct TreeNode* invertTree(struct TreeNode*r){if(!r)return r;struct TreeNode*t=r->left;r->left=invertTree(r->right);r->right=invertTree(t);return r;}
