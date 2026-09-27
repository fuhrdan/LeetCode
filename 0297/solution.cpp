#include <string>
#include <sstream>
using namespace std;class Codec{void s(TreeNode*n,string&r){if(!n){r+="# ";return;}r+=to_string(n->val)+" ";s(n->left,r);s(n->right,r);}TreeNode*d(istringstream&in){string x;in>>x;if(x=="#")return nullptr;auto n=new TreeNode(stoi(x));n->left=d(in);n->right=d(in);return n;}public:string serialize(TreeNode*r){string x;s(r,x);return x;}TreeNode* deserialize(string data){istringstream in(data);return d(in);}};
