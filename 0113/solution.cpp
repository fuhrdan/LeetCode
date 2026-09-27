#include <vector>
using namespace std;class Solution{vector<vector<int>>o;void f(TreeNode*n,int t,vector<int>&v){if(!n)return;v.push_back(n->val);t-=n->val;if(!n->left&&!n->right&&t==0)o.push_back(v);f(n->left,t,v);f(n->right,t,v);v.pop_back();}public:vector<vector<int>> pathSum(TreeNode*r,int t){vector<int>v;f(r,t,v);return o;}};
