#include <math.h>
int closestValue(struct TreeNode*r,double t){int b=r->val;while(r){if(fabs(r->val-t)<fabs(b-t))b=r->val;r=t<r->val?r->left:r->right;}return b;}
