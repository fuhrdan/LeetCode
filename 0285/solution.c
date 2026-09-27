struct TreeNode* inorderSuccessor(struct TreeNode*r,struct TreeNode*p){struct TreeNode*s=0;while(r){if(p->val<r->val){s=r;r=r->left;}else r=r->right;}return s;}
