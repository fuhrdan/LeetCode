#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;class Solution{void f(TreeNode*n,vector<int>&a){if(!n)return;f(n->left,a);a.push_back(n->val);f(n->right,a);}public:vector<int> closestKValues(TreeNode*r,double t,int k){vector<int>a;f(r,a);nth_element(a.begin(),a.begin()+k,a.end(),[&](int x,int y){return abs(x-t)<abs(y-t);});a.resize(k);return a;}};
