#include <stdlib.h>

static void dfs(struct TreeNode* node, int depth, int** result, int* count, int* cap)
{
    if (node == NULL)
    {
        return;
    }

    if (depth == *count)
    {
        if (*count == *cap)
        {
            *cap *= 2;
            *result = realloc(*result, *cap * sizeof(int));
        }

        (*result)[(*count)++] = node->val;
    }

    dfs(node->right, depth + 1, result, count, cap);
    dfs(node->left, depth + 1, result, count, cap);
}

int* rightSideView(struct TreeNode* root, int* returnSize)
{
    int cap = 16;
    int count = 0;
    int* retVal = malloc(cap * sizeof(int));

    dfs(root, 0, &retVal, &count, &cap);

    *returnSize = count;
    return retVal;
}
