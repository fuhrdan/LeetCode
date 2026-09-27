#include <vector>
using namespace std;

class Solution
{
    vector<int> result;

    void dfs(TreeNode* node, int depth)
    {
        if (node == nullptr)
        {
            return;
        }

        if (depth == result.size())
        {
            result.push_back(node->val);
        }

        dfs(node->right, depth + 1);
        dfs(node->left, depth + 1);
    }

public:
    vector<int> rightSideView(TreeNode* root)
    {
        dfs(root, 0);
        return result;
    }
};
