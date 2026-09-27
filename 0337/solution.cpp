#include <algorithm>
class Solution{pair<int,int>f(TreeNode*n){if(!n)return{0,0};auto l=f(n->left),r=f(n->right);return{n->val+l.second+r.second,max(l.first,l.second)+max(r.first,r.second)};}public:int rob(TreeNode*r){auto x=f(r);return std::max(x.first,x.second);}};
