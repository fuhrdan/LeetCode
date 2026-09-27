#include <vector>
using namespace std;class Solution{vector<TreeNode*> f(int l,int r){if(l>r)return{nullptr};vector<TreeNode*>o;for(int x=l;x<=r;x++){auto L=f(l,x-1),R=f(x+1,r);for(auto a:L)for(auto b:R)o.push_back(new TreeNode(x,a,b));}return o;}public:vector<TreeNode*> generateTrees(int n){return n?f(1,n):vector<TreeNode*>{};}};
