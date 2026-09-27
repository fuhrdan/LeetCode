import java.util.*;

class Solution
{
    private final List<Integer> result = new ArrayList<>();

    private void dfs(TreeNode node, int depth)
    {
        if (node == null)
        {
            return;
        }

        if (depth == result.size())
        {
            result.add(node.val);
        }

        dfs(node.right, depth + 1);
        dfs(node.left, depth + 1);
    }

    public List<Integer> rightSideView(TreeNode root)
    {
        dfs(root, 0);
        return result;
    }
}
