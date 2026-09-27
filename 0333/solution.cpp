#include <climits>
#include <algorithm>
class Solution{struct R{bool ok;int n,lo,hi;};int b=0;R f(TreeNode*x){if(!x)return{true,0,INT_MAX,INT_MIN};auto l=f(x->left),r=f(x->right);if(l.ok&&r.ok&&x->val>l.hi&&x->val<r.lo){R z{true,l.n+r.n+1,l.n?l.lo:x->val,r.n?r.hi:x->val};b=std::max(b,z.n);return z;}return{false,0,0,0};}public:int largestBSTSubtree(TreeNode*r){f(r);return b;}};
