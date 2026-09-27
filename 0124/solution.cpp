#include <climits>
#include <algorithm>
class Solution{int b=INT_MIN;int f(TreeNode*n){if(!n)return 0;int l=std::max(0,f(n->left)),r=std::max(0,f(n->right));b=std::max(b,n->val+l+r);return n->val+std::max(l,r);}public:int maxPathSum(TreeNode*r){f(r);return b;}};
