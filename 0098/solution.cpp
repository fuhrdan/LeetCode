#include <climits>
class Solution{bool f(TreeNode*n,long long lo,long long hi){return !n||(n->val>lo&&n->val<hi&&f(n->left,lo,n->val)&&f(n->right,n->val,hi));}public:bool isValidBST(TreeNode*r){return f(r,LLONG_MIN,LLONG_MAX);}};
