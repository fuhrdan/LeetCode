#include <algorithm>
class Solution{int b=0;void f(TreeNode*n,int p,int len){if(!n)return;len=n->val==p+1?len+1:1;b=std::max(b,len);f(n->left,n->val,len);f(n->right,n->val,len);}public:int longestConsecutive(TreeNode*r){if(!r)return 0;f(r,r->val-1,0);return b;}};
