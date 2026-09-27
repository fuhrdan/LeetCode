#include <vector>
using namespace std;class Solution{int i=0;TreeNode*f(vector<int>&p,vector<int>&in,int l,int r){if(l>r)return nullptr;int v=p[i++],k=l;while(in[k]!=v)k++;return new TreeNode(v,f(p,in,l,k-1),f(p,in,k+1,r));}public:TreeNode* buildTree(vector<int>&p,vector<int>&in){return f(p,in,0,in.size()-1);}};
