class Solution{public:TreeNode* inorderSuccessor(TreeNode*r,TreeNode*p){TreeNode*s=nullptr;while(r){if(p->val<r->val){s=r;r=r->left;}else r=r->right;}return s;}};
