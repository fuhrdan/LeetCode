static int f(struct TreeNode*n,int v){if(!n)return 0;v=v*10+n->val;if(!n->left&&!n->right)return v;return f(n->left,v)+f(n->right,v);}int sumNumbers(struct TreeNode*r){return f(r,0);}
