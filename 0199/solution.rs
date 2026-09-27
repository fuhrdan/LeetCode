use std::cell::RefCell;
use std::rc::Rc;

impl Solution
{
    pub fn right_side_view(root: Option<Rc<RefCell<TreeNode>>>) -> Vec<i32>
    {
        fn dfs(
            node: &Option<Rc<RefCell<TreeNode>>>,
            depth: usize,
            result: &mut Vec<i32>)
        {
            if let Some(node) = node
            {
                let node = node.borrow();

                if depth == result.len()
                {
                    result.push(node.val);
                }

                dfs(&node.right, depth + 1, result);
                dfs(&node.left, depth + 1, result);
            }
        }

        let mut result = Vec::new();
        dfs(&root, 0, &mut result);
        result
    }
}
