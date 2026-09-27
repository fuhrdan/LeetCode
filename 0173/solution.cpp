#include <stack>
using namespace std;class BSTIterator{stack<TreeNode*>s;void p(TreeNode*n){while(n){s.push(n);n=n->left;}}public:BSTIterator(TreeNode*r){p(r);}int next(){auto n=s.top();s.pop();p(n->right);return n->val;}bool hasNext(){return !s.empty();}};
