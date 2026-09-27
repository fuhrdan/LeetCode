#include <vector>
using namespace std;class Solution{public:vector<int> preorderTraversal(TreeNode*r){vector<int>o,st;if(!r)return o;vector<TreeNode*>q{r};while(!q.empty()){auto n=q.back();q.pop_back();o.push_back(n->val);if(n->right)q.push_back(n->right);if(n->left)q.push_back(n->left);}return o;}};
