class Solution{int h(TreeNode*n){if(!n)return 0;int a=h(n->left);if(a<0)return-1;int b=h(n->right);if(b<0||abs(a-b)>1)return-1;return 1+max(a,b);}public:bool isBalanced(TreeNode*r){return h(r)>=0;}};
