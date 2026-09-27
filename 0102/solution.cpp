#include <vector>
#include <queue>
using namespace std;class Solution{public:vector<vector<int>> levelOrder(TreeNode*r){vector<vector<int>>o;if(!r)return o;queue<TreeNode*>q;q.push(r);while(!q.empty()){int n=q.size();vector<int>v;while(n--){auto x=q.front();q.pop();v.push_back(x->val);if(x->left)q.push(x->left);if(x->right)q.push(x->right);}o.push_back(v);}return o;}};
