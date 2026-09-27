#include <vector>
#include <queue>
#include <map>
using namespace std;class Solution{public:vector<vector<int>> verticalOrder(TreeNode*r){if(!r)return{};map<int,vector<int>>m;queue<pair<TreeNode*,int>>q;q.push({r,0});while(!q.empty()){auto[n,c]=q.front();q.pop();m[c].push_back(n->val);if(n->left)q.push({n->left,c-1});if(n->right)q.push({n->right,c+1});}vector<vector<int>>o;for(auto&[k,v]:m)o.push_back(v);return o;}};
