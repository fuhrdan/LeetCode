//*****************************************************************************
//** 2265. Count Nodes Equal to Average of Subtree                  leetcode **
//*****************************************************************************

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

static void getSubtree(struct TreeNode* root, int* sum, int* count, int* matches)
{
    if (root == NULL)
    {
        *sum = 0;
        *count = 0;
        return;
    }

    int leftSum = 0;
    int leftCount = 0;
    int rightSum = 0;
    int rightCount = 0;

    getSubtree(root->left, &leftSum, &leftCount, matches);
    getSubtree(root->right, &rightSum, &rightCount, matches);

    *sum = leftSum + rightSum + root->val;
    *count = leftCount + rightCount + 1;

    if ((*sum / *count) == root->val)
    {
        (*matches)++;
    }
}

int averageOfSubtree(struct TreeNode* root)
{
    int sum = 0;
    int count = 0;
    int matches = 0;

    getSubtree(root, &sum, &count, &matches);

    return matches;
}