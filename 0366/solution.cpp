#include <vector>
#include <algorithm>
using namespace std;class Solution{vector<vector<int>>o;int f(TreeNode*n){if(!n)return-1;int h=1+max(f(n->left),f(n->right));if(h==o.size())o.push_back({});o[h].push_back(n->val);return h;}public:vector<vector<int>> findLeaves(TreeNode*r){f(r);return o;}};
