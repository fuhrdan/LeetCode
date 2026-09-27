#include <vector>
using namespace std;class Solution{TreeNode*f(vector<int>&a,int l,int r){if(l>r)return nullptr;int m=(l+r)/2;return new TreeNode(a[m],f(a,l,m-1),f(a,m+1,r));}public:TreeNode* sortedListToBST(ListNode*h){vector<int>a;for(;h;h=h->next)a.push_back(h->val);return f(a,0,a.size()-1);}};
