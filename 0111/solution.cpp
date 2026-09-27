class Solution{public:int minDepth(TreeNode*r){if(!r)return 0;if(!r->left)return 1+minDepth(r->right);if(!r->right)return 1+minDepth(r->left);return 1+min(minDepth(r->left),minDepth(r->right));}};
