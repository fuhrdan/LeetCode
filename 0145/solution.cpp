#include <vector>
#include <algorithm>
using namespace std;class Solution{public:vector<int> postorderTraversal(TreeNode*r){vector<int>o;vector<TreeNode*>st;if(r)st.push_back(r);while(!st.empty()){auto n=st.back();st.pop_back();o.push_back(n->val);if(n->left)st.push_back(n->left);if(n->right)st.push_back(n->right);}reverse(o.begin(),o.end());return o;}};
