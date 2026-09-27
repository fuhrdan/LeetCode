using System.Collections.Generic;

public class Solution
{
    private readonly List<int> result = new();

    private void Dfs(TreeNode node, int depth)
    {
        if (node == null)
        {
            return;
        }

        if (depth == result.Count)
        {
            result.Add(node.val);
        }

        Dfs(node.right, depth + 1);
        Dfs(node.left, depth + 1);
    }

    public IList<int> RightSideView(TreeNode root)
    {
        Dfs(root, 0);
        return result;
    }
}
