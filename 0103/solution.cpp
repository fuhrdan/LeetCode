#include <vector>
#include <queue>
using namespace std;class Solution{public:vector<vector<int>> zigzagLevelOrder(TreeNode*r){vector<vector<int>>o;if(!r)return o;queue<TreeNode*>q;q.push(r);bool rev=false;while(!q.empty()){int n=q.size();vector<int>v(n);for(int i=0;i<n;i++){auto x=q.front();q.pop();v[rev?n-1-i:i]=x->val;if(x->left)q.push(x->left);if(x->right)q.push(x->right);}o.push_back(v);rev=!rev;}return o;}};
