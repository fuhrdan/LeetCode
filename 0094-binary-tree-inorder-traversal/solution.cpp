#include <vector>
using namespace std;class Solution{public:vector<int> inorderTraversal(TreeNode*r){vector<int>o;vector<TreeNode*>st;while(r||!st.empty()){while(r){st.push_back(r);r=r->left;}r=st.back();st.pop_back();o.push_back(r->val);r=r->right;}return o;}};
