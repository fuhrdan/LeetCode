class Solution{TreeNode*p=nullptr;void f(TreeNode*n){if(!n)return;f(n->right);f(n->left);n->right=p;n->left=nullptr;p=n;}public:void flatten(TreeNode*r){f(r);}};
