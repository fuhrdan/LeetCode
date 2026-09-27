#include <stack>
using namespace std;class Solution{public:int kthSmallest(TreeNode*r,int k){stack<TreeNode*>s;while(r||!s.empty()){while(r){s.push(r);r=r->left;}r=s.top();s.pop();if(--k==0)return r->val;r=r->right;}return-1;}};
