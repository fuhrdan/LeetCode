static struct TreeNode*prev;static void f(struct TreeNode*n){if(!n)return;f(n->right);f(n->left);n->right=prev;n->left=0;prev=n;}void flatten(struct TreeNode*r){prev=0;f(r);}
