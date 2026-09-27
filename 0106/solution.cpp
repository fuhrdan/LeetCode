#include <vector>
using namespace std;class Solution{int i;TreeNode*f(vector<int>&in,int l,int r,vector<int>&p){if(l>r)return nullptr;int v=p[i--],k=l;while(in[k]!=v)k++;auto n=new TreeNode(v);n->right=f(in,k+1,r,p);n->left=f(in,l,k-1,p);return n;}public:TreeNode* buildTree(vector<int>&in,vector<int>&p){i=p.size()-1;return f(in,0,in.size()-1,p);}};
