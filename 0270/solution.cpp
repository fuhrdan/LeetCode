#include <cmath>
class Solution{public:int closestValue(TreeNode*r,double t){int b=r->val;while(r){if(abs(r->val-t)<abs(b-t))b=r->val;r=t<r->val?r->left:r->right;}return b;}};
