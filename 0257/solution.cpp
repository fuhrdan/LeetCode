#include <vector>
#include <string>
using namespace std;class Solution{vector<string>o;void f(TreeNode*n,string s){if(!n)return;s+=s.empty()?to_string(n->val):"->"+to_string(n->val);if(!n->left&&!n->right)o.push_back(s);else{f(n->left,s);f(n->right,s);}}public:vector<string> binaryTreePaths(TreeNode*r){f(r,"");return o;}};
