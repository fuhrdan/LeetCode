int maxDepth(struct TreeNode*r){if(!r)return 0;int a=maxDepth(r->left),b=maxDepth(r->right);return 1+(a>b?a:b);}
